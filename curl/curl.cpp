#include <stdio.h>
#include <curl/curl.h>

int main(void)
{
	CURL *curl;
	CURLcode res;

	curl_global_init(CURL_GLOBAL_ALL);

	curl = curl_easy_init();
	if (curl) {

		const char *message_fmt = "{\"skillsetId\": %d, \"agtAvail\": %d, \"agtInSrvc\": %d, \"agtOnSkl\": %d, \"agtNtRdy\": %d, \"callWait\": %d, \"lngWaitTime\": %d, \"maxWaitTime\": %d, \"totWaitTime\": %d, \"expWaitTime\": %d, \"callAfXfr\": %d, \"lngLogin\": %d, \"agtOnDn\": %d, \"skillsetState\": %d, \"agtUnavil\": %d}";
		char message[1024];
		sprintf_s(message, message_fmt, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);

		curl_easy_setopt(curl, CURLOPT_URL, "https://rtsm.requestcatcher.com/");
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, message);

		res = curl_easy_perform(curl);
		if (res != CURLE_OK)
		{
			fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
		}

		curl_easy_cleanup(curl);
	}

	curl_global_cleanup();

	return 0;
}