
#include "sdk\sdk.h"
using namespace sdk;
using namespace sdk::offys;
auto encrypt(std::string mess) -> std::string {
	return mess;
}
auto decrypt(std::string mess) -> std::string {
	return mess;
}
auto visuals_theard() -> void {
	if (settings_t.visuals.chams) features::visuals::c_glow->think();
	if (settings_t.visuals.glow_esp) features::visuals::c_chams->think();
	std::this_thread::sleep_for(std::chrono::milliseconds(1));
}
auto misc_theard() -> void {
	std::this_thread::sleep_for(std::chrono::milliseconds(1));
}
auto aimbot_theard() -> void {
	if (settings_t.aimbot) features::aimbot::c_aimbot->think();
	std::this_thread::sleep_for(std::chrono::milliseconds(1));
}
auto triggerbot_theard() -> void {
	std::this_thread::sleep_for(std::chrono::milliseconds(1));
}
auto main() -> uint32_t
{
	c_memory->get_processid("csgo.exe");
	c_memory->attach("csgo.exe");
	offys::clientdll = c_memory->get_module("client_panorama.dll");
	offys::enginedll = c_memory->get_module("engine.dll");
	do {
		globals::local = csgo::c_client->get_local();
		globals::weapon = globals::local->get_weapon();
		features::aimbot::c_aimbot->think();
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	} while (true);
    return 0;

}

