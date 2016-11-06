#include "Config.hpp"
#include "PhaseLyricsTunnel.hpp"
#include "PhaseMoireGeneration.hpp"
#include "PhaseMoireSpin.hpp"
#include "PhaseSpectrum2D.hpp"
#include "PhaseSpectrum3D.hpp"
#include "PhaseTest.hpp"
#include "PhaseTetrahedronSpin.hpp"
#include "PhaseTextGeneration.hpp"
#include "Storyboard.hpp"
#include "Time.hpp"
#include <iostream>

int main() {
	// For random
	srand(time(NULL));

	Vector2 maxBgSize(Vector2::ScreenSize);
	Sprite* bg = new Sprite("Storyboard\\Background\\Blank.png", Vector2::Midpoint, Layer::Background);
	bg->ScaleVector(Config::I()->songStart.ms, Config::I()->songEnd.ms, maxBgSize, maxBgSize);
	bg->Color(0, 0, GetColor[GC::CYAN], GetColor[GC::CYAN]);
	bg->Fade(0, Time("00:01:756").ms, 0.0f, 1.0f, Easing::CubicIn);
	Config::I()->SwitchSpriteColor(bg, Time("00:27:019").ms, Time("00:28:282").ms, GetColor[GC::MUSTARD], GetColor[GC::CYAN], Config::I()->mspb, Config::I()->mspb);
	Config::I()->SwitchSpriteColor(bg, Time("00:30:177").ms, Time("00:30:808").ms, GetColor[GC::CHEWEDBUBBLEGUM], GetColor[GC::MUSTARD], Config::I()->mspb / 4, Config::I()->mspb / 4);
	Config::I()->SwitchSpriteColor(bg, Time("00:30:808").ms + Config::I()->mspb, Time("00:33:335").ms, GetColor[GC::MUSTARD], GetColor[GC::CHEWEDBUBBLEGUM], Config::I()->mspb, Config::I()->mspb);
	Config::I()->SwitchSpriteColor(bg, Time("00:33:650").ms, Time("00:33:966").ms, GetColor[GC::LEMONGRASS], GetColor[GC::CHEWEDBUBBLEGUM], Config::I()->mspb / 4, Config::I()->mspb / 4);
	Config::I()->SwitchSpriteColor(bg, Time("00:34:914").ms, Time("00:35:229").ms, GetColor[GC::TURQUOISE], GetColor[GC::LEMONGRASS], Config::I()->mspb / 4, Config::I()->mspb / 4);
	Config::I()->SwitchSpriteColor(bg, Time("00:36:177").ms, Time("00:36:493").ms, GetColor[GC::SPIDERMANRED], GetColor[GC::TURQUOISE], Config::I()->mspb / 4, Config::I()->mspb / 4);
	Config::I()->SwitchSpriteColor(bg, Time("00:37:124").ms, Time("00:38:387").ms, GetColor[GC::PEACH], GetColor[GC::SPIDERMANRED], Config::I()->mspb / 2, Config::I()->mspb / 2);
	Config::I()->SwitchSpriteColor(bg, Time("00:39:966").ms, Time("00:40:598").ms, GetColor[GC::MUSTARD], GetColor[GC::PEACH], Config::I()->mspb / 4, Config::I()->mspb / 4);
	Config::I()->SwitchSpriteColor(bg, Time("00:40:914").ms, Time("00:42:177").ms, GetColor[GC::BURGANDY], GetColor[GC::MUSTARD], Config::I()->mspb / 2, Config::I()->mspb / 2);

	std::cout << "PhaseSpectrum2D..." << std::endl;
	PhaseSpectrum2D phaseSpectrum2D;
	std::cout << "PhaseMoireGeneration..." << std::endl;
	PhaseMoireGeneration phaseMoireGeneration;
	std::cout << "PhaseMoireSpin..." << std::endl;
	PhaseMoireSpin phaseMoireSpin;
	std::cout << "PhaseLyricsTunnel..." << std::endl; 
	PhaseLyricsTunnel phaseLyricsTunnel;
	std::cout << "PhaseTetrahedronSpin..." << std::endl;
	PhaseTetrahedronSpin phaseTetrahedronSpin;
	std::cout << "PhaseSpectrum3D..." << std::endl;
	PhaseSpectrum3D phaseSpectrum3D;
	std::cout << "PhaseTextGeneration..." << std::endl;
	PhaseTextGeneration phaseTextGeneration;

	// PhaseTest phaseTest;

	Storyboard::Instance()->Write(Config::I()->storyboardPath);
	//std::cin.get();
	return 0;
}