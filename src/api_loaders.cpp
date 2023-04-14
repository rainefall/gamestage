#include "gamestage/api_loaders.h"

#ifdef GAMESTAGE_STATIC_LINK
#include "gamestage/static.h"
#include "gamestage/Video/static.h"
#else
#include "dynalo/dynalo.hpp"
#endif

#ifndef GAMESTAGE_STATIC_LINK
	static dynalo::library* gs_gamestage_frameworklib;
	static dynalo::library* gs_gamestage_videolib;
	static dynalo::library* gs_gamestage_clientlib;
	static dynalo::library* gs_gamestage_serverlib;
#endif

IFramework* gamestage_GetFrameworkAPI() {
#ifdef GAMESTAGE_STATIC_LINK
	return get_framework_api();
#else
	// open module lib file
	// todo, please do not hardcode gamestage_sdl
	gs_gamestage_frameworklib = new dynalo::library("./"+dynalo::to_native_name("gamestage_sdl"));
	// get function pointers from lib file
	auto framework_api_factory = gs_gamestage_frameworklib->get_function<IFramework*()>("get_framework_api");
	return framework_api_factory();
#endif
}

IVideo* gamestage_GetVideoAPI() {
#ifdef GAMESTAGE_STATIC_LINK
	return get_video_api();
#else
	// open module lib file
	// todo, please do not hardcode gamestage_gl
	gs_gamestage_videolib = new dynalo::library("./"+dynalo::to_native_name("gamestage_gl"));
	// get function pointers from lib file
	auto video_api_factory = gs_gamestage_videolib->get_function<IVideo*()>("get_video_api");
	return video_api_factory();
#endif
}
/*
gamestage_clientAPI* gamestage_GetClientAPI() {
	// allocate api structure
	gamestage_clientAPI* api = (gamestage_clientAPI*)malloc(sizeof(gamestage_clientAPI));
	if (!api)
		return NULL;

#ifdef GAMESTAGE_STATIC_LINK
	// directly assign function pointers
	api->gamestage_ClientInit = &gamestage_ClientInit;
	api->gamestage_ClientExit = &gamestage_ClientExit;
#else
	// open module lib file
	gs_gamestage_clientlib = new dynalo::library("./"+dynalo::to_native_name("client"));
	// get function pointers from lib file
	api->gamestage_ClientInit = gs_gamestage_clientlib->get_function<void(gamestage_videoAPI*)>("gamestage_ClientInit");
	api->gamestage_ClientExit = gs_gamestage_clientlib->get_function<void()>("gamestage_ClientExit");
#endif
	return api;
}

gamestage_serverAPI* gamestage_GetServerAPI() {
	// allocate api structure
	gamestage_serverAPI* api = (gamestage_serverAPI*)malloc(sizeof(gamestage_serverAPI));
	if (!api)
		return NULL;

#ifdef GAMESTAGE_STATIC_LINK
	// directly assign function pointers
	api->gamestage_ServerInit = &gamestage_ServerInit;
	api->gamestage_ServerExit = &gamestage_ServerExit;
#else
	// open module lib file
	gs_gamestage_serverlib = new dynalo::library("./"+dynalo::to_native_name("server"));
	// get function pointers from lib file
	api->gamestage_ServerInit = gs_gamestage_serverlib->get_function<void()>("gamestage_ServerInit");
	api->gamestage_ServerExit = gs_gamestage_serverlib->get_function<void()>("gamestage_ServerExit");
#endif
	return api;
}

*/