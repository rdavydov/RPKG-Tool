#pragma once

#include <cstddef>

#ifdef __cplusplus
extern "C"
{
#endif

	struct JsonString;
	
	struct ResourceConverter
	{
		/**
		 * Convert a binary resource found at [p_ResourceFilePath] to its json representation and
		 * store it in the [p_OutputFilePath] file on the filesystem.
		 * 
		 * The [p_Simple] parameter controls whether the json output will be simplified or will
		 * be more verbose. The more verbose output contains additional type information for every
		 * field.
		 *
		 * Returns [true] on success, or [false] otherwise.
		 */
		bool (*FromResourceFileToJsonFile)(const char* p_ResourceFilePath, const char* p_OutputFilePath, bool p_Simple);

		/**
		 * Convert a resource from an in-memory buffer to its json representation and store it in
		 * the [p_OutputFilePath] file on the filesystem. The [p_ResourceData] parameter must
		 * point to the binary data of the resource and the [p_Size] parameter must be the size of
		 * the resource in bytes.
		 * 
		 * The [p_Simple] parameter controls whether the json output will be simplified or will
		 * be more verbose. The more verbose output contains additional type information for every
		 * field.
		 *
		 * Returns [true] on success, or [false] otherwise.
		 */
		bool (*FromMemoryToJsonFile)(const void* p_ResourceData, size_t p_Size, const char* p_OutputFilePath, bool p_Simple);

		/**
		 * Convert a binary resource found at [p_ResourceFilePath] to its json representation and
		 * store it in memory as a [JsonString]. After using it, the [JsonString] must be cleaned up
		 * by passing it to the [FreeJsonString] function.
		 *
		 * The [p_Simple] parameter controls whether the json output will be simplified or will
		 * be more verbose. The more verbose output contains additional type information for every
		 * field.
		 *
		 * If the operation fails, this function will return [nullptr].
		 */
		JsonString* (*FromResourceFileToJsonString)(const char* p_ResourceFilePath, bool p_Simple);

		/**
		 * Convert a resource from an in-memory buffer to its json representation and store it in
		 * memory as a [JsonString]. The [p_ResourceData] parameter must point to the binary data
		 * of the resource and the [p_Size] parameter must be the size of the resource in bytes.
		 * After using it, the [JsonString] must be cleaned up by passing it to the
		 * [FreeJsonString] function.
		 *
		 * The [p_Simple] parameter controls whether the json output will be simplified or will
		 * be more verbose. The more verbose output contains additional type information for every
		 * field.
		 *
		 * If the operation fails, this function will return [nullptr].
		 */
		JsonString* (*FromMemoryToJsonString)(const void* p_ResourceData, size_t p_Size, bool p_Simple);

		/**
		 * Clean up an in-memory json string. The [JsonString] becomes invalid after a call to
		 * this function, and attempting to use it results in undefined behavior.
		 */
		void (*FreeJsonString)(JsonString* p_JsonString);
	};

#ifdef __cplusplus
}
#endif
