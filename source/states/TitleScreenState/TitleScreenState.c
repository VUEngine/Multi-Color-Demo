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
#include <TitleScreenState.h>
#include <TransparencyState.h>


//---------------------------------------------------------------------------------------------------------
// 												DECLARATIONS
//---------------------------------------------------------------------------------------------------------

extern StageROMDef TITLE_SCREEN_STAGE_ST;


//---------------------------------------------------------------------------------------------------------
// 											CLASS'S DEFINITION
//---------------------------------------------------------------------------------------------------------

// class's constructor
void TitleScreenState::constructor()
{
	Base::constructor();

	// add event listeners
	Object::addEventListener(Object::safeCast(this), Object::safeCast(this), (EventListener)TitleScreenState::onTransitionOutComplete, kEventTransitionOutComplete);
}

// class's destructor
void TitleScreenState::destructor()
{
	// remove event listeners
	Object::removeEventListener(Object::safeCast(this), Object::safeCast(this), (EventListener)TitleScreenState::onTransitionOutComplete, kEventTransitionOutComplete);

	// destroy base
	Base::destructor();
}

// state's enter
void TitleScreenState::enter(void* owner __attribute__ ((unused)))
{
	// call base
	Base::enter(this, owner);

	// load stage
	GameState::loadStage(GameState::safeCast(this), (StageDefinition*)&TITLE_SCREEN_STAGE_ST, NULL, true);

	// start clocks to start animations
	GameState::startClocks(GameState::safeCast(this));

	// enable user input
	Game::enableKeypad(Game::getInstance());

	// show screen
	Camera::startEffect(Camera::getInstance(), kShow);
}

void TitleScreenState::processUserInput(UserInput userInput)
{
	if(userInput.pressedKey & (K_STA | K_SEL | K_A | K_B))
	{
		TitleScreenState::loadNextState(this);
	}
}

void TitleScreenState::loadNextState()
{
	// disable user input
	Game::disableKeypad(Game::getInstance());

	// transition layer animation
	AnimatedEntity transitionLayerEntity = AnimatedEntity::safeCast(Container::getChildByName(Container::safeCast(Game::getStage(Game::getInstance())), "TRNSLYR", true));
	if(transitionLayerEntity)
	{
		AnimatedEntity::playAnimation(transitionLayerEntity, "FadeOut");
	}
}

// handle event
void TitleScreenState::onTransitionOutComplete(Object eventFirer __attribute__ ((unused)))
{
	// hide screen
	Camera::startEffect(Camera::getInstance(), kHide);

	// change to next stage
	Game::changeState(Game::getInstance(), GameState::safeCast(TransparencyState::getInstance()));
}