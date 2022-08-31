#pragma once
#include "../dxlib_ext/dxlib_ext.h"

namespace dxe {

	class Camera {
	public :

		Camera(){}
		Camera(int screen_w, int screen_h) {
			screen_w_ = screen_w;
			screen_h_ = screen_h;
			aspect_ = (float)screen_w_ / (float)screen_h_;
		}

		int screen_w_ = 0 ;
		int screen_h_ = 0 ;

		// カメラの３次元座標
		tnl::Vector3 pos_ = tnl::Vector3(0, 0, -100.0f);
		// カメラが３次元のどこを画面の中央にとらえているか
		tnl::Vector3 target_ = tnl::Vector3(0, 0, 0);
		// カメラの『上』を定義するアッパーベクトル
		tnl::Vector3 up_ = tnl::Vector3(0, 1, 0);

		// カメラの画角 ( 度 )
		float angle_ = tnl::ToRadian(60.0f);
		// カメラのアスペクト比 ( 縦横比 )
		float aspect_ = 1.0f;
		// カメラに映る範囲の最近距離
		float near_ = 1.0f;
		// カメラに映る範囲の最遠距離
		float far_ = 5000.0f;

		tnl::Matrix view_;
		tnl::Matrix proj_;

		void update() {
			view_ = tnl::Matrix::LookAtLH(pos_, target_, up_);
			proj_ = tnl::Matrix::PerspectiveFovLH(angle_, aspect_, near_, far_);

			MATRIX view, proj;
			memcpy(view.m, view_.m, sizeof(float) * 16);
			memcpy(proj.m, proj_.m, sizeof(float) * 16);
			SetCameraViewMatrix(view);
			SetupCamera_ProjectionMatrix(proj);
		}

	};

}
