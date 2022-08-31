#include "dxlib_ext_texture.h"

namespace dxe {

	std::shared_ptr<Texture> Texture::CreateFromFile(const std::string& file_path)
	{
		std::shared_ptr<Texture> tex = std::shared_ptr<Texture>( new Texture() );
		tex->file_path_ = file_path;
		tex->gfx_hdl_ = LoadGraph(file_path.c_str()) ;
		return tex;
	}

	//std::shared_ptr<Texture> Texture::CreateFromFile(const std::string& file_path, uint32_t all_size_w, uint32_t all_size_h, uint32_t num_frame_w, uint32_t num_frame_h)
	//{
	//	std::shared_ptr<Texture> tex = std::make_shared<Texture>();
	//	tex->file_path_ = file_path;

	//	uint32_t frame_size_w = all_size_w / num_frame_w;
	//	uint32_t frame_size_h = all_size_h / num_frame_h;
	//	tex->hdls_.resize( num_frame_w * num_frame_h );

	//	LoadDivGraph(file_path.c_str(), tex->hdls_.size(), num_frame_w, num_frame_h, frame_size_w, frame_size_h, tex->hdls_.data());

	//	return tex;
	//}

}

