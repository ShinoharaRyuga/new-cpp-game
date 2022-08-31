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

		// �t�@�C���p�X�̎擾
		const std::string& getFilePath() { return file_path_; }
		// �O���t�B�b�N�n���h���̎擾
		int getGraphHandle() { return gfx_hdl_; }

		// ����
		// arg1... �t�@�C���p�X
		static std::shared_ptr<Texture> CreateFromFile( const std::string& file_path );

		// �t���[����������
		// arg1... �t�@�C���p�X
		// arg2... �����S�̃T�C�Y
		// arg3... �c���S�̃T�C�Y
		// arg4... �������t���[����
		// arg5... �c�����t���[����
		//static std::shared_ptr<Texture> CreateFromFile( const std::string& file_path, uint32_t all_size_w, uint32_t all_size_h, uint32_t num_frame_w, uint32_t num_frame_h );

	};

}

