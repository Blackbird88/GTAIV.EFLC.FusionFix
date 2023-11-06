module;

#include <common.hxx>

export module widescreenfix;

import common;
import comvars;
import settings;
import natives;
import renderthread;

#define SCREEN_WIDTH ((float)*rage__grcDevice__ms_nActiveWidth)
#define SCREEN_HEIGHT ((float)*rage__grcDevice__ms_nActiveHeight)
#define DEFAULT_SCREEN_WIDTH 1280.0f
#define DEFAULT_SCREEN_HEIGHT 720.0f
#define DEFAULT_ASPECT_RATIO (16.0f / 9.0f)
#define SCREEN_ASPECT_RATIO Natives::GetAspectRatio()

class WidescreenFix 
{
public:
    static inline float f075 = 0.75f;
    static inline float f01152 = 1152.0f;
    static inline float bordersMult = -5.0f;
    static inline int32_t bordersTimer = 0;

    static void Update() 
    {
        f075 = 0.75f * DEFAULT_ASPECT_RATIO / SCREEN_ASPECT_RATIO;
        f01152 = 1152.0f * DEFAULT_ASPECT_RATIO / SCREEN_ASPECT_RATIO;

        if (bordersTimer < (*CTimer__m_snTimeInMilliseconds))
            bordersMult = -5.0f;
    }

    static inline void* CSprite2d__DrawRectAddr;
    static void CSprite2d__DrawRect(Vector4 const& pos, Color32 const& col)
    {
        reinterpret_cast<void(__cdecl*)(Vector4 const*, Color32 const*)>(CSprite2d__DrawRectAddr)(&pos, &col);
    }

    static inline void* CSprite2d__DrawAddr;
    static void CSprite2d__Draw(Vector4 const& pos, Color32 const& col) 
    {
        reinterpret_cast<void(__cdecl*)(Vector4 const*, Color32 const*)>(CSprite2d__DrawAddr)(&pos, &col);
    }

    static void DrawBorders(bool letter, bool pillar, bool force) 
    {
        float aspectRatio = SCREEN_ASPECT_RATIO;
        if (force)
            bordersMult = 1.0f;

        // Letterbox
        if (letter && aspectRatio < DEFAULT_ASPECT_RATIO) 
        {
            float letterboxHeight = SCREEN_WIDTH / DEFAULT_ASPECT_RATIO;
            float letterboxY = (SCREEN_HEIGHT - letterboxHeight) / 2.0f;

            Color32 col = { 0, 0, 0, 255 };
            Vector4 rect = { 0.0f, 0.0f, SCREEN_WIDTH, letterboxY * bordersMult };
            CSprite2d__DrawRect(rect, col);

            rect = { 0.0f, SCREEN_HEIGHT - (letterboxY * bordersMult), SCREEN_WIDTH, SCREEN_HEIGHT };
            CSprite2d__DrawRect(rect, col);
        }

        // Pillarbox
        if (pillar && aspectRatio > DEFAULT_ASPECT_RATIO)
        {
            float pillarWidth = SCREEN_WIDTH - (SCREEN_HEIGHT * DEFAULT_ASPECT_RATIO);
            float halfPillarWidth = pillarWidth / 2.0f;
            Color32 col = { 0, 0, 0, 255 };
            Vector4 rect = { 0.0f, 0.0f, halfPillarWidth * bordersMult, SCREEN_HEIGHT };
            CSprite2d__DrawRect(rect, col);

            rect = { SCREEN_WIDTH - (halfPillarWidth * bordersMult), 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT };
            CSprite2d__DrawRect(rect, col);
        }

        bordersTimer = (*CTimer__m_snTimeInMilliseconds) + 500;
        bordersMult += 2.0f * (*fTimeStep);
        if (bordersMult >= 1.0f)
            bordersMult = 1.0f;
    }

    static void DrawCutsceneBorders() 
    {
        auto dc = new T_CB_Generic_NoArgs([]() { DrawBorders(true, true, false); });
        if (dc)
            dc->Append();
    }

    static void DrawLoadingScreen(Vector4 rect, float z, float min1, float max1, float min2, float max2, Color32 const& col) 
    {
        float aspectRatio = SCREEN_ASPECT_RATIO;
        bool isWide = (aspectRatio > 1.5f);
        bool isNotClipped = (rect.fW - rect.fY) / DEFAULT_SCREEN_HEIGHT < 1.0f;

        if (isWide && !isNotClipped) 
        {
            float scale = DEFAULT_ASPECT_RATIO / aspectRatio;
            rect.fX = rect.fX * scale;
            rect.fZ = rect.fZ * scale;

            float offset = (SCREEN_WIDTH - ((DEFAULT_SCREEN_WIDTH * (float)SCREEN_WIDTH / DEFAULT_SCREEN_WIDTH) * DEFAULT_ASPECT_RATIO / SCREEN_ASPECT_RATIO)) / 2;
            rect.fX += offset;
            rect.fZ += offset;
        }

        CSprite2d__Draw(rect, col);

        if (isWide) 
            DrawBorders(false, true, true);
    }

    static inline injector::hook_back<void(__cdecl*)(void)> hbInitEpisodeSelect;
    static void InitEpisodeSelect() 
    {
        Update();
        hbInitEpisodeSelect.fun();
    }

    static inline injector::hook_back<void(__fastcall*)(int32_t*, void*, int32_t, const char*, int32_t*, int32_t)> hbUITexture__Load;
    static void __fastcall UITexture__Load(int32_t* ui, void*, int32_t txdSlot, const char* texName, int32_t* arg4, int32_t arg5) 
    {
        float aspectRatio = SCREEN_ASPECT_RATIO;
        const char* name = texName;
        if (aspectRatio >= (21.0f / 9.0f))
            name = "offline_21by9";

        hbUITexture__Load.fun(ui, 0, txdSlot, name, arg4, arg5);
    }

    WidescreenFix()
    {
        // CSprite2d
        auto pattern = find_pattern("6A 00 E8 ? ? ? ? 8B 44 24 08 83 C4 04 F3 0F 10 40", "6A 00 E8 ? ? ? ? D9 EE 8B 44 24 0C");
        CSprite2d__DrawRectAddr = pattern.get_first(0);

        pattern = find_pattern("8B 44 24 04 6A 00 FF 74 24 0C", "8B 44 24 08 D9 E8 6A 00");
        CSprite2d__DrawAddr = pattern.get_first(0);

        // Fix "auto" aspect ratio
        pattern = find_pattern("75 67 E8 75 CB FC FF", "75 5B E8 ? ? ? ? 85 C0 7E 52 E8");
        injector::WriteMemory<uint8_t>(pattern.get_first(0), 0xEB, true);

        pattern = find_pattern("6A 01 F3 0F 5E C8 B9", "6A 01 B9 ? ? ? ? E8 ? ? ? ? D9 54 24 1C");
        injector::WriteMemory<uint8_t>(pattern.get_first(1), 0, true);

        // Fix cellphone
        pattern = find_pattern("F3 0F 59 0D ? ? ? ? 0F 28 C1 F3 0F 59 44 24 ? F3 0F 11 44 24 ? 0F 28 C1 F3 0F 59 44 24 ? F3 0F 59 4C 24 ? F3 0F 11 44 24 ? F3 0F 10 44 24", "F3 0F 59 0D ? ? ? ? 0F 28 D1 F3 0F 59 54 24");
        injector::WriteMemory<void*>(pattern.get_first(4), &f075, true);

        // Fix episode menu select
        pattern = find_pattern("E8 ? ? ? ? 8B 4E 08 6A 00 8B 01 6A 10 8B 40 08 68 ? ? ? ? FF D0 85 C0 74 13 68 ? ? ? ? 68 ? ? ? ? 8B C8 E8 ? ? ? ? EB 02 33 C0 8D 4C 24 14 51 8B C8 A3 ? ? ? ? C7 44 24 ? ? ? ? ? E8 ? ? ? ? E8 ? ? ? ? E9", "E8 ? ? ? ? 64 8B 0D ? ? ? ? 8B 11 8B 4A 08 8B 01 8B 50 08 53 6A 10 68 ? ? ? ? FF D2 3B C3 74 1A");
        hbInitEpisodeSelect.fun = injector::GetBranchDestination(pattern.get_first(0)).get();
        injector::MakeCALL(pattern.get_first(0), InitEpisodeSelect);
        
        // Add new tex offline_21by9
        pattern = find_pattern("E8 ? ? ? ? 64 A1 ? ? ? ? 6A 00 8B 38 6A 10 8B 4F 08 68 ? ? ? ? 8B 01 8B 40 08 FF D0 85 C0 74 15", "E8 ? ? ? ? 55 68 ? ? ? ? 68");
        hbUITexture__Load.fun = injector::GetBranchDestination(pattern.get_first(0)).get();
        injector::MakeCALL(pattern.get_first(0), UITexture__Load);

        pattern = find_pattern("F3 0F 59 0D ? ? ? ? F3 0F 59 D3 F3 0F 5C C1", "F3 0F 59 05 ? ? ? ? F3 0F 59 CA F3 0F 59 CC");
        injector::WriteMemory<void*>(pattern.get_first(4), &f01152, true);

        // Cutscene borders
        pattern = hook::pattern("83 EC 14 B9 ? ? ? ? E8 ? ? ? ? 84 C0");
        injector::MakeJMP(pattern.get_first(0), DrawCutsceneBorders, true);

        // Loadingscreens
        pattern = find_pattern("E8 ? ? ? ? 83 C4 2C E8 ? ? ? ? E9", "E8 ? ? ? ? 83 C4 2C E8 ? ? ? ? EB 73");
        injector::MakeCALL(pattern.get_first(0), DrawLoadingScreen, true);

        pattern = find_pattern("E8 ? ? ? ? 83 C4 2C E8 ? ? ? ? 8A 54 24 0F", "E8 ? ? ? ? 83 C4 2C E8 ? ? ? ? 8B 35");
        injector::MakeCALL(pattern.get_first(0), DrawLoadingScreen, true);

        pattern = find_pattern("E8 ? ? ? ? 83 C4 2C 5F 5E 5B 83 C4 28", "E8 ? ? ? ? 83 C4 2C 5F 5E 5D 5B 83 C4 20");
        injector::MakeCALL(pattern.get_first(0), DrawLoadingScreen, true);

        FusionFix::onGameProcessEvent() += []()
        {
            Update();
        };
    }
} WidescreenFix;