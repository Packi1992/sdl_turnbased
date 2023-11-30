#pragma once

#include <global.h>

#include <gamebase.h>
#include <recthelper.h>
#include <autocast_ptr.h>

class ExampleGame;
class WarState;

class ExampleGame final : public Game
{
public:
	ExampleGame();

	bool HandleEvent( const Event & event ) override;
};

class ExampleGameState : public GameState
{
public:
	[[nodiscard]] ExampleGame & GetGame() const override { return dynamic_cast<ExampleGame &>( GameState::GetGame() ); }

	using GameState::GameState;
};

class WarState : public ExampleGameState
{
public:
    // ctor
    using ExampleGameState::ExampleGameState;

    void Init() override;
    void UnInit() override;

    bool HandleEvent( const Event & event ) override;
    void Update( const u32 frame, const u32 totalMSec, const float deltaT ) override;
    void Render( const u32 frame, const u32 totalMSec, const float deltaT ) override;

    Color GetClearColor() const override { return Color { 0, 0, 0, SDL_ALPHA_OPAQUE }; }
};