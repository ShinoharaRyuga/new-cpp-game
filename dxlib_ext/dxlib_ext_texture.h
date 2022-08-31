#pragma once
#include <vector>
#include <string>
#include <tuple>
#include <memory>
#include "DxLib.h"
namespace dxe {

	class Texture final {
	private :
		Texture(){}
		std::string file_path_;
		int gfx_hdl_ = 0;
	public :
		~Texture() {
			DeleteGraph(gfx_hdl_);
		}

		// ファイルパスの取得
		const std::string& getFilePath() { return file_path_; }
		// グラフィックハンドルの取得
		int getGraphHandle() { return gfx_hdl_; }

		// 生成
		// arg1... ファイルパス
		static std::shared_ptr<Texture> CreateFromFile( const std::string& file_path );

		// フレーム分割生成
		// arg1... ファイルパス
		// arg2... 横幅全体サイズ
		// arg3... 縦幅全体サイズ
		// arg4... 横方向フレーム数
		// arg5... 縦方向フレーム数
		//static std::shared_ptr<Texture> CreateFromFile( const std::string& file_path, uint32_t all_size_w, uint32_t all_size_h, uint32_t num_frame_w, uint32_t num_frame_h );

	};

}

