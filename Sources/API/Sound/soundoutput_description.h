/*
**  ClanLib SDK
**  Copyright (c) 1997-2020 The ClanLib Team
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

#include <memory>

namespace clan
{
	/// \addtogroup clanSound_Audio_Mixing clanSound Audio Mixing
	/// \{

	class SoundOutput_Description_Impl;

	/// \brief Sound output description class.
	class SoundOutput_Description
	{
	public:
		/// \brief Constructs a sound output description.
		SoundOutput_Description();
		~SoundOutput_Description();

		/// \brief Returns the mixing frequency for the sound output device.
		int get_mixing_frequency() const;

		/// \brief Returns the mixing latency in milliseconds.
		int get_mixing_latency() const;

		/// \brief Sets the mixing frequency for the sound output device.
		void set_mixing_frequency(int frequency);

		/// \brief Sets the mixing latency in milliseconds.
		void set_mixing_latency(int latency);

	private:
		std::shared_ptr<SoundOutput_Description_Impl> impl;
	};

	/// \}
}
