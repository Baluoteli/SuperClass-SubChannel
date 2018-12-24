//
//  Agora Media SDK
//
//  Created by Sting Feng in 2015-05.
//  Copyright (c) 2015 Agora IO. All rights reserved.
//
#pragma once
#include "IAgoraRtcEngine.h"
#include <string>

namespace agora {
	namespace rtc {

		struct RtcEngineContextEx {
			IRtcEngineEventHandler* eventHandler;
			bool isExHandler;
			bool forceAlternativeNetworkEngine;
			const char* appId;
			void* context;
			std::string deviceId;
			std::string configDir;
			std::string dataDir;
			std::string pluginDir;
			bool isMaster;
			RtcEngineContextEx()
				:eventHandler(NULL)
				, isExHandler(false)
				, forceAlternativeNetworkEngine(false)
				, appId(NULL)
				, context(NULL)
				, isMaster(false)
			{}
		};

		class IRtcEngine2 : public IRtcEngine
		{
		public:
			virtual int initializeEx(const RtcEngineContextEx& context) = 0;

			/**
			* Specify video stream parameters based on video profile
			* @param [in] width
			*        width of video resolution in pixel
			* @param [in] height
			*        height of video resolution in pixel
			* @param [in] frameRate
			*        frame rate in fps
			* @param [in] bitrate
			*        bit rate in kbps
			* @return return 0 if success or an error code
			*/
			virtual int setVideoProfileEx(int width, int height, int frameRate, int bitrate) = 0;
		};

	}
}
