#include "dependencies/utilities/csgo.hpp"
#include "core/features/features.hpp"
#include "core/hooks/hooks.hpp"
#include "core/hooks/functions/event_globals.hpp"

void __fastcall hooks::fire_event::hook(void* thisptr, void* edx, i_game_event* gameEvent, bool bServerOnly, bool bClientOnly) {
    if (gameEvent) { // Nullptr check just incase!
        auto name = gameEvent->get_name();

        // Event list: https://wiki.alliedmods.net/Counter-Strike:_Global_Offensive_Events
        if (!strcmp(name, "bullet_impact")) {
            printf("bullet_impact\n");
        } else if (!strcmp(name, "round_end")) {
            printf("round_end\n");
            event_globals::round_ended = true;
        } else if (!strcmp(name, "round_start")) {
            printf("round_start\n");
            event_globals::round_ended = false;
        }
    }

    original(thisptr, edx, gameEvent, bServerOnly, bClientOnly);
}