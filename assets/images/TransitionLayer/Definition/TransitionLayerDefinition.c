/* VUEngine - Virtual Utopia Engine <http://vuengine.planetvb.com/>
 * A universal game engine for the Nintendo Virtual Boy
 *
 * Copyright (C) 2007, 2018 by Jorge Eremiev<jorgech3@gmail.com> and Christian Radke <chris@vr32.de>
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
//												INCLUDES
//---------------------------------------------------------------------------------------------------------

#include <libgccvb.h>
#include <TransitionEntity.h>
#include <BgmapAnimatedSprite.h>


//---------------------------------------------------------------------------------------------------------
//												DECLARATIONS
//---------------------------------------------------------------------------------------------------------

extern BYTE TransitionLayerTiles[];
extern BYTE TransitionLayerMap[];


//---------------------------------------------------------------------------------------------------------
//												DEFINITIONS
//---------------------------------------------------------------------------------------------------------

// a function which defines the frames to play
AnimationFunctionROMDef TRANSITION_LAYER_FADE_IN_ANIM =
{
	// number of frames of this animation function
	19,

	// frames to play in animation
	{18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0},

	// number of cycles a frame of animation is displayed
	1,

	// whether to play it in loop or not
	false,

	// method to call on function completion
	NULL,

	// function's name
	"FadeIn",
};

// a function which defines the frames to play
AnimationFunctionROMDef TRANSITION_LAYER_FADE_OUT_ANIM =
{
	// number of frames of this animation function
	19,

	// frames to play in animation
	{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18},

	// number of cycles a frame of animation is displayed
	1,

	// whether to play it in loop or not
	false,

	// method to call on function completion
	(EventListener)&TransitionEntity_onTransitionComplete,

	// function's name
	"FadeOut",
};

// an animation definition
AnimationDescriptionROMDef TRANSITION_LAYER_ANIM =
{
	// animation functions
	{
		(AnimationFunction*)&TRANSITION_LAYER_FADE_IN_ANIM,
		(AnimationFunction*)&TRANSITION_LAYER_FADE_OUT_ANIM,
		NULL,
	}
};

CharSetROMDef TRANSITION_LAYER_CH =
{
	// number of chars, depending on allocation type:
	// __ANIMATED_SINGLE*, __ANIMATED_SHARED*: number of chars of a single animation frame (cols * rows)
	// __ANIMATED_MULTI, __NOT_ANIMATED: sum of all chars
	3,

	// allocation type
	// (__ANIMATED_SINGLE, __ANIMATED_SINGLE_OPTIMIZED, __ANIMATED_SHARED, __ANIMATED_SHARED_COORDINATED, __ANIMATED_MULTI or __NOT_ANIMATED)
	__ANIMATED_SINGLE_OPTIMIZED,

	// char definition
	TransitionLayerTiles,
};

TextureROMDef TRANSITION_LAYER_TX =
{
	// charset definition
	(CharSetDefinition*)&TRANSITION_LAYER_CH,

	// bgmap definition
	TransitionLayerMap,

	// cols (max 64)
	48,

	// rows (max 64)
	28,

	// padding for affine transformations
	{0, 0},

	// number of frames, depending on charset's allocation type:
	// __ANIMATED_SINGLE*, __ANIMATED_SHARED*, __NOT_ANIMATED: 1
	// __ANIMATED_MULTI: total number of frames
	__ANIMATED_SINGLE_OPTIMIZED,

	// palette number (0-3)
	1,

	// recyclable
	false,
};

BgmapSpriteROMDef TRANSITION_LAYER_SPRITE =
{
	{
		// sprite's type
		__TYPE(BgmapAnimatedSprite),

		// texture definition
		(TextureDefinition*)&TRANSITION_LAYER_TX,

		// transparent (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// displacement
		{0, 0, 0, 0},
	},

	// bgmap mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
	// make sure to use the proper corresponding sprite type throughout the definition (BgmapSprite or ObjectSprite)
	__WORLD_BGMAP,

	// pointer to affine / hbias manipulation function
	NULL,

	// display mode (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,
};

BgmapSpriteROMDef* const TRANSITION_LAYER_SPRITES[] =
{
	&TRANSITION_LAYER_SPRITE,
	NULL
};

TransitionEntityROMDef TRANSITION_LAYER_AE =
{
	{
		// class allocator
		__TYPE(TransitionEntity),

		// sprites
		(SpriteROMDef**)TRANSITION_LAYER_SPRITES,

		// collision shapes
		(ShapeDefinition*)NULL,

		// size
		// if 0, width and height will be inferred from the first sprite's texture's size
		{0, 0, 0},

		// gameworld's character's type
		0,

		// physical specification
		(PhysicalSpecification*)NULL,
	},

	// pointer to the animation definition for the item
	(AnimationDescription*)&TRANSITION_LAYER_ANIM,

	// initial animation
	"FadeIn",
};
