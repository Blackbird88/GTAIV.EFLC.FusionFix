module;

#include <common.hxx>

export module altdialogue;

import common;
import comvars;
import settings;

std::vector<std::vector<std::tuple<std::string_view, uint32_t>>> gAltDialogueVars =
{
    {
        { "badman_1", 65020 },
        { "badman_1", 65021 },
        { "bell2", 64953 },
        { "bell2", 64954 },
        { "bell3m", 64981 },
        { "bell3m", 64983 },
        { "bell3m", 64980 },
        { "bell3p", 64980 },
        { "bell5", 64968 },
        { "bell7", 64939 },
        { "bernie1", 64936 },
        { "bernie2", 64937 },
        { "bernie2", 64938 },
        { "bernie3", 65005 },
        { "brian_2", 65023 },
        { "brian_2", 65024 },
        { "brian_3", 65025 },
        { "brian_3", 65026 },
        { "brucie2", 65006 },
        { "brucie3a", 64951 },
        { "brucie3b", 64951 },
        { "brucie3_meetguy", 64951 },
        { "brucie3_meetguy", 64949 },
        { "brucie4", 64726 },
        { "brucie4", 64984 },
        { "brucie4", 64727 },
        { "brucie4", 64728 },
        { "brucie4", 64729 },
        { "brucie4", 64730 },
        { "cherise", 64743 },
        { "cherise", 64748 },
        { "cia1", 64930 },
        { "cia3", 64676 },
        { "derrick2", 65007 },
        { "derrick2", 65008 },
        { "derrick3", 64978 },
        { "derrick3", 64979 },
        { "eddie1", 64740 },
        { "eddie1", 64746 },
        { "eddie2", 64747 },
        //{ "elizabeta2", 64645 },
        { "faustin7", 64732 },
        { "faustin7", 64731 },
        { "finale1a", 64733 },
        { "finale1a", 64734 },
        { "finale1a", 64735 },
        { "finale1c", 64768 },
        { "finale2", 64969 },
        { "finale2", 64970 },
        { "finale2", 64971 },
        { "finale2", 64972 },
        { "francis4", 65011 },
        { "francis6", 64933 },
        { "francis6", 64932 },
        { "gambetti1", 64720 },
        { "gambetti1", 64721 },
        { "gerry3b", 64942 },
        { "gerry3b", 64941 },
        { "gerry4", 64641 },
        { "gerry5", 64944 },
        { "gracie", 64750 },
        { "hossan_1", 65027 },
        { "hossan_1", 65028 },
        { "ilyena", 64744 },
        { "ilyena", 64745 },
        { "ilyena", 64751 },
        { "ilyena_calls", 64744 },
        { "ilyena_calls", 64745 },
        { "ivan_1", 65029 },
        { "ivan_1", 65030 },
        { "jacob1", 64933 },
        { "jacob1", 64934 },
        { "jacob1", 64935 },
        { "jacob2", 64674 },
        { "jacob3m", 64771 },
        { "jacob3m", 64758 },
        { "jeff_1", 65033 },
        { "jeff_1_mission", 65033 },
        { "jeff_2", 65035 },
        { "jeff_3", 65041 },
        { "jimmy1", 64563 },
        { "jimmy1", 64572 },
        { "jimmy1", 64573 },
        { "jimmy1", 64574 },
        { "manny1", 64567 },
        { "manny1", 64568 },
        { "marnie1", 64738 },
        { "marnie1", 64752 },
        { "marnie2", 64739 },
        { "marnie2", 64753 },
        { "mel", 64737 },
        { "mel", 64754 },
        { "michelle1", 64564 },
        { "michelle1", 64565 },
        { "michelle1", 64566 },
        { "packie1", 64940 },
        { "packie2", 64718 },
        { "packie2", 64719 },
        { "packie3", 64965 },
        { "packie3", 64966 },
        { "pathos1", 64755 },
        { "pathos2", 64742 },
        { "pathos2", 64756 },
        { "playboy2", 65010 },
        { "playboy3", 64962 },
        { "playboy3", 64963 },
        { "ray2", 64955 },
        { "ray2", 64956 },
        { "ray2", 64957 },
        //{ "roman10m", 64575 },
        { "roman11", 64687 },
        { "roman11", 64689 },
        { "roman12", 64964 },
        { "roman13", 64642 },
        { "roman13", 64623 },
        { "roman14", 64624 },
        { "roman2", 64975 },
        { "roman2", 64976 },
        { "roman3", 64717 },
        { "roman4", 64960 },
        { "roman4", 64961 },
        { "roman5", 64716 },
        { "roman6", 64763 },
        { "roman6", 64762 },
        { "roman7", 64724 },
        { "roman7", 64725 },
        { "roman8m", 64772 },
        { "roman8m", 64767 },
        { "sara2", 64757 },
        { "sara_1", 65031 },
        { "sara_1", 65032 },
    },
    {
        { "ashley1", 38744 },
        { "ashley2", 39237 },
        { "ashley2", 39238 },
        //{ "ashley2", 39236 },
        { "billy1", 39209 },
        { "billy1", 39211 },
        { "billy1", 39214 },
        { "billy1", 39216 },
        { "billy1", 39215 },
        { "billy1", 39217 },
        { "billy3", 38772 },
        { "billy3", 38770 },
        { "billy3", 38773 },
        { "billy3", 38771 },
        { "billy4", 39218 },
        { "billy6", 39203 },
        { "brian", 39241 },
        { "elizabeta1", 39240 },
        { "elizabeta2", 39202 },
        { "elizabeta3", 38710 },
        { "jim1", 39246 },
        { "jim1", 39243 },
        { "jim1", 39244 },
        { "jim1", 39245 },
        { "jim4", 39247 },
        { "jim5", 39182 },
        { "jim5", 39183 },
        { "jim5", 39184 },
        { "jim6", 38774 },
        { "malc1", 39242 },
        { "ray1", 39239 },
        { "ray3", 38767 },
        { "stubbs2", 39233 },
    },
    {
        { "arnaud1", 43696 },
        { "arnaud2", 43697 },
        { "arnaud2", 43696 },
        { "brother1", 43670 },
        { "brother1", 43669 },
        { "brother2", 42993 },
        { "brother3", 43587 },
        { "bulgarin1", 43799 },
        { "bulgarin1", 43800 },
        { "bulgarin2", 42939 },
        { "bulgarin2", 42940 },
        { "bulgarin2", 42927 },
        { "rocco1", 43704 },
        { "rocco1", 43671 },
        { "tony1", 43701 },
        { "tony1", 43708 },
        { "tony1", 43706 },
        { "tony1", 43703 },
        { "tony1", 43707 },
        { "tony1", 43705 },
        { "tony10", 43694 },
        { "tony10", 43695 },
        { "tony11", 43672 },
        { "tony2", 43004 },
        { "tony2", 43007 },
        { "tony2", 43005 },
        { "tony2", 43006 },
        { "tony2", 43008 },
        { "tony2", 43009 },
        { "tony2", 43010 },
        { "tony3", 42928 },
        { "tony3", 42929 },
        { "tony4a", 42937 },
        { "tony4a", 42936 },
        { "tony4b", 42938 },
        { "tony6", 43646 },
        { "tony6", 43647 },
        { "tony6", 43648 },
        { "tony7", 42994 },
        { "tony7", 42996 },
        { "tony7", 42995 },
        { "tonym1", 43684 },
        { "tonym2", 43685 },
        { "tonym3", 43686 },
        { "tonym4", 43687 },
        { "tonym5", 43688 },
        { "tonym6", 43689 },
        { "tonym7", 43690 },
        { "tonym8", 43691 },
        { "yusuf2", 42910 },
        { "yusuf3", 43668 },
        //{ "yusuf4", 42911 },
    }
};

class AltDialogue
{
public:
    AltDialogue()
    {
        FusionFix::onInitEvent() += []()
        {
            FusionFixSettings.SetCallback("PREF_ALTDIALOGUE", [](int32_t value) {
                auto pGlobals = *rage__scrProgram__ms_pGlobals;
                for (auto& it : gAltDialogueVars[*_dwCurrentEpisode])
                    pGlobals[std::get<1>(it)] = value;
            });
        };

        FusionFix::onGameProcessEvent() += []()
        {
            static auto altdialogue = FusionFixSettings.GetRef("PREF_ALTDIALOGUE");
            if (altdialogue->get())
            {
                if (*rage__scrProgram__ms_pGlobals)
                {
                    static uintptr_t* pGlobals = nullptr;
                    if (pGlobals != *rage__scrProgram__ms_pGlobals)
                    {
                        pGlobals = *rage__scrProgram__ms_pGlobals;
                        for (auto& it : gAltDialogueVars[*_dwCurrentEpisode])
                            pGlobals[std::get<1>(it)] = FusionFixSettings("PREF_ALTDIALOGUE");
                    }
                }
            }
        };
    }
} AltDialogue;