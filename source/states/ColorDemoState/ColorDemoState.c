/* VUEngine - Virtual Utopia Engine <http://vuengine.planetvb.com/>
 * A universal game engine for the Nintendo Virtual Boy
 *
 * Copyright (C) 2007, 2018 by Jorge Eremiev <jorgech3@gmail.com> and Christian Radke <chris@vr32.de>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
 * associated documentation files (the "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or substantial
 * portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT
 * LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN
 * NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */


//---------------------------------------------------------------------------------------------------------
// 												INCLUDES
//---------------------------------------------------------------------------------------------------------

#include <string.h>

#include <Game.h>
#include <VIPManager.h>
#include <Camera.h>
#include <AnimatedEntity.h>
#include <GameEvents.h>
#include <ColorDemoState.h>


//---------------------------------------------------------------------------------------------------------
// 												DECLARATIONS
//---------------------------------------------------------------------------------------------------------

extern StageROMDef COLOR_DEMO_STAGE_ST;
extern BrightnessRepeatROMDef GRADIENT_BRIGHTNESS_REPEAT;
extern BrightnessRepeatROMDef DEFAULT_BRIGHTNESS_REPEAT;


//---------------------------------------------------------------------------------------------------------
// 											CLASS'S DEFINITION
//---------------------------------------------------------------------------------------------------------

// class's constructor
void ColorDemoState::constructor()
{
	Base::constructor();

	this->cbColTabEntity = NULL;
	this->cbDitherEntity = NULL;
	this->cbTranspEntity = NULL;
	this->mode = 0;
}

// class's destructor
void ColorDemoState::destructor()
{
	// destroy base
	Base::destructor();
}

// state's enter
void ColorDemoState::enter(void* owner __attribute__ ((unused)))
{
	// call base
	Base::enter(this, owner);

	// load stage
	GameState::loadStage(GameState::safeCast(this), (StageDefinition*)&COLOR_DEMO_STAGE_ST, NULL, true);

	// get entities
	this->cbColTabEntity = Entity::safeCast(Container::getChildByName(Container::safeCast(Game::getStage(Game::getInstance())), "CBColTab", true));
	this->cbDitherEntity = Entity::safeCast(Container::getChildByName(Container::safeCast(Game::getStage(Game::getInstance())), "CBDither", true));
	this->cbTranspEntity = Entity::safeCast(Container::getChildByName(Container::safeCast(Game::getStage(Game::getInstance())), "CBTransp", true));

	// start clocks to start animations
	GameState::startClocks(GameState::safeCast(this));

	// enable user input
	Game::enableKeypad(Game::getInstance());

	// init entity visibility
	Entity::hide(this->cbColTabEntity);
	Entity::hide(this->cbTranspEntity);

	// start fade in effect
	Camera::startEffect(Camera::getInstance(),
		kFadeTo, // effect type
		0, // initial delay (in ms)
		NULL, // target brightness
		0, // delay between fading steps (in ms)
		NULL, // callback function
		NULL // callback scope
	);
}

void ColorDemoState::processUserInput(UserInput userInput)
{
	if(userInput.pressedKey & (K_LL | K_RL | K_LT | K_LU | K_RU))
	{
		this->mode = (this->mode > 0) ? this->mode - 1 : MAX_MODE;
		ColorDemoState::setMode(this);
	}
	else if(userInput.pressedKey & (K_LR | K_RR | K_RT | K_LD | K_RD))
	{
		this->mode = (this->mode < MAX_MODE) ? this->mode + 1 : 0;
		ColorDemoState::setMode(this);
	}
}

void ColorDemoState::setMode()
{
	switch(this->mode)
	{
		case 0:
		{
			Entity::hide(this->cbColTabEntity);
			Entity::hide(this->cbDitherEntity);
			Entity::hide(this->cbTranspEntity);

			Entity::show(this->cbDitherEntity);

			_vipRegisters[__BRTA] = 32;
			_vipRegisters[__BRTB] = 64;
			_vipRegisters[__BRTC] = 32;
			VIPManager::setupBrightnessRepeat(VIPManager::getInstance(), (BrightnessRepeatDefinition*)&DEFAULT_BRIGHTNESS_REPEAT);

			break;
		}
		case 1:
		{
			Entity::hide(this->cbColTabEntity);
			Entity::hide(this->cbDitherEntity);
			Entity::hide(this->cbTranspEntity);

			Entity::show(this->cbColTabEntity);

			_vipRegisters[__BRTA] = 1;
			_vipRegisters[__BRTB] = 2;
			_vipRegisters[__BRTC] = 0;
			VIPManager::setupBrightnessRepeat(VIPManager::getInstance(), (BrightnessRepeatDefinition*)&GRADIENT_BRIGHTNESS_REPEAT);

			break;
		}
		case 2:
		{
			Entity::hide(this->cbColTabEntity);
			Entity::hide(this->cbDitherEntity);
			Entity::hide(this->cbTranspEntity);

			Entity::show(this->cbTranspEntity);

			_vipRegisters[__BRTA] = 32;
			_vipRegisters[__BRTB] = 64;
			_vipRegisters[__BRTC] = 32;
			VIPManager::setupBrightnessRepeat(VIPManager::getInstance(), (BrightnessRepeatDefinition*)&DEFAULT_BRIGHTNESS_REPEAT);

			break;
		}
	}
}
