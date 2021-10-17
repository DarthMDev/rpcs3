#pragma once

#include "Emu/Io/camera_handler_base.h"

class null_camera_handler final : public camera_handler_base
{
public:
	null_camera_handler() : camera_handler_base() {}
	
	void open_camera() override {};
	void close_camera() override {};
	void start_camera() override {};
	void stop_camera() override {};

	void set_format(s32 format, u32 bytes_per_pixel) override
	{
		m_format = format;
		m_bytes_per_pixel = bytes_per_pixel;
	}

	void set_frame_rate(u32 frame_rate) override
	{
		m_frame_rate = frame_rate;
	}

	void set_resolution(u32 width, u32 height) override
	{
		m_width = width;
		m_height = height;
	};

	void set_mirrored(bool mirrored) override
	{
		m_mirrored = mirrored;
	}

	u64 frame_number() const override
	{
		return 0;
	}

	bool get_image(u8* /*buf*/, u64 /*size*/, u32& width, u32& height, u64& frame_number, u64& bytes_read) override
	{
		width = 0;
		height = 0;
		frame_number = 0;
		bytes_read = 0;
		return true;
	}
};