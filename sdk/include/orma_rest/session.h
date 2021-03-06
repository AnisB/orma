#pragma once

// Bento includes
#include <bento_memory/common.h>

// SDK includes
#include "orma_rest/credentials.h"
#include "orma_rest/curl_api.h"
#include "orma_rest/ping_response.h"
#include "orma_rest/market.h"
#include "orma_rest/database.h"

namespace orma
{
	class TSession
	{
		ALLOCATOR_BASED;
	public:
		// Cst & Dst
		TSession(bento::IAllocator& allocator);
		~TSession();

		void init();
		void terminate();

		// Interactions
		bool ping(TPingResponse& pingResponse);
		bool market_list(const TCredentials& credentials, TMarket& market);
		bool database_list(const TCredentials& credentials, TDatabase& market);

	private:
		curl::CurlInstance* _curlInstance;
		curl::CurlMessage* _curlMessage;
	public:
		bento::IAllocator& _allocator;
	};
}