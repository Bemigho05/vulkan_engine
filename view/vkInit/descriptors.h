#pragma once

#include "../../config.h"

namespace vkInit {
	struct DescriptorSetLayoutData {
		int count;
		std::vector<int> indices;
		std::vector<vk::DescriptorType> types;
		std::vector<int> counts;
		std::vector<vk::ShaderStageFlags> stages;
	};

	vk::DescriptorSetLayout make_descriptor_set_layout(vk::Device device, const DescriptorSetLayoutData& bindings);

	vk::DescriptorPool make_descriptor_pool(vk::Device device, uint32_t size, const DescriptorSetLayoutData& bindings);

	vk::DescriptorSet allocate_descriptor_set(
	vk::Device device, vk::DescriptorPool descriptorPool,
	vk::DescriptorSetLayout layout);
	
}
