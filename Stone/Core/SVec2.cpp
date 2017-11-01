#include "SVec2.h"

const SVec2 SVec2::ZERO(0.0f, 0.0f);
const SVec2 SVec2::ONE(1.0f, 1.0f);
const SVec2 SVec2::UNIT_X(1.0f, 0.0f);
const SVec2 SVec2::UNIT_Y(0.0f, 1.0f);
const SVec2 SVec2::ANCHOR_MIDDLE(0.5f, 0.5f);
const SVec2 SVec2::ANCHOR_BOTTOM_LEFT(0.0f, 1.0f);
const SVec2 SVec2::ANCHOR_TOP_LEFT(0.0f, 0.0f);
const SVec2 SVec2::ANCHOR_BOTTOM_RIGHT(1.0f, 1.0f);
const SVec2 SVec2::ANCHOR_TOP_RIGHT(1.0f, 0.0f);
const SVec2 SVec2::ANCHOR_MIDDLE_RIGHT(1.0f, 0.5f);
const SVec2 SVec2::ANCHOR_MIDDLE_LEFT(0.0f, 0.5f);
const SVec2 SVec2::ANCHOR_MIDDLE_TOP(0.5f, 0.5f);
const SVec2 SVec2::ANCHOR_MIDDLE_BOTTOM(0.5f, 1.0f);

//cocos2d-x
//const SVec2 SVec2::ZERO(0.0f, 0.0f);
//const SVec2 SVec2::ONE(1.0f, 1.0f);
//const SVec2 SVec2::UNIT_X(1.0f, 0.0f);
//const SVec2 SVec2::UNIT_Y(0.0f, 1.0f);
//const SVec2 SVec2::ANCHOR_MIDDLE(0.5f, 0.5f);
//const SVec2 SVec2::ANCHOR_BOTTOM_LEFT(0.0f, 0.0f);
//const SVec2 SVec2::ANCHOR_TOP_LEFT(0.0f, 1.0f);
//const SVec2 SVec2::ANCHOR_BOTTOM_RIGHT(1.0f, 0.0f);
//const SVec2 SVec2::ANCHOR_TOP_RIGHT(1.0f, 1.0f);
//const SVec2 SVec2::ANCHOR_MIDDLE_RIGHT(1.0f, 0.5f);
//const SVec2 SVec2::ANCHOR_MIDDLE_LEFT(0.0f, 0.5f);
//const SVec2 SVec2::ANCHOR_MIDDLE_TOP(0.5f, 1.0f);
//const SVec2 SVec2::ANCHOR_MIDDLE_BOTTOM(0.5f, 0.0f);