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
**    Mark Page
*/

#include "Display/precomp.h"
#include "render_batch_buffer.h"
#include "sprite_impl.h"
#include "API/Display/Render/blend_state_description.h"
#include "API/Display/2D/canvas.h"

namespace clan
{

RenderBatchBuffer::RenderBatchBuffer() : current_gpu_buffer(0)
{
}

TransferBuffer RenderBatchBuffer::get_transfer_buffer(GraphicContext &gc)
{
	if (transfer_buffers[current_gpu_buffer].is_null())
	{
		transfer_buffers[current_gpu_buffer] = TransferBuffer(gc, buffer_size, usage_stream_draw);
	}
	return transfer_buffers[current_gpu_buffer];
}

void RenderBatchBuffer::next_buffer()
{
	current_gpu_buffer++;
	if (current_gpu_buffer == num_gpu_buffers)
		current_gpu_buffer = 0;
}

}