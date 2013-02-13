/*
**  ClanLib SDK
**  Copyright (c) 1997-2012 The ClanLib Team
**
**  This software is provided 'as-is', without any express or implied
**  warranty.  In no event will the authors be held liable for any damages
**  arising from the use of this software.
**
**  Permission is granted to anyone to use this software for any purpose,
**  including commercial applications, and to alter it and redistribute it
**  freely, subject to the following restrictions:
**
**  1. The origin of this software must not be misrepresented; you must not
**     claim that you wrote the original software. If you use this software
**     in a product, an acknowledgment in the product documentation would be
**     appreciated but is not required.
**  2. Altered source versions must be plainly marked as such, and must not be
**     misrepresented as being the original software.
**  3. This notice may not be removed or altered from any source distribution.
**
**  Note: Some of the libraries ClanLib may link to may have additional
**  requirements or restrictions.
**
**  File Author(s):
**
**    Magnus Norddahl
*/

#pragma once

namespace clan
{

class AxisAlignedBoundingBox
{
public:
	AxisAlignedBoundingBox() { }
	AxisAlignedBoundingBox(const clan::Vec3f &aabb_min, const clan::Vec3f &aabb_max) : aabb_min(aabb_min), aabb_max(aabb_max) { }
	AxisAlignedBoundingBox(const AxisAlignedBoundingBox &aabb, const clan::Vec3f &barycentric_min, const clan::Vec3f &barycentric_max)
	: aabb_min(clan::mix(aabb.aabb_min, aabb.aabb_max, barycentric_min)), aabb_max(clan::mix(aabb.aabb_min, aabb.aabb_max, barycentric_max)) { }

	clan::Vec3f center() const { return (aabb_max + aabb_min) * 0.5f; }
	clan::Vec3f extents() const { return (aabb_max - aabb_min) * 0.5f; }

	clan::Vec3f aabb_min;
	clan::Vec3f aabb_max;
};

}
