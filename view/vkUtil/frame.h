#pragma once
#include "../../config.h"
#include "memory.h"

namespace vkUtil {
	struct UBO {
		glm::mat4 view;
		glm::mat4 projection;
		glm::mat4 viewProjection;
	};

	/**
		Holds the data structures associated with a "Frame"
	*/
	class SwapChainFrame {
	public:

		vk::Device logicalDevice;
		vk::PhysicalDevice physicalDevice;


		// swapchain
		vk::Image image;
		vk::ImageView imageView;
		vk::Framebuffer framebuffer;
		vk::Image depthBuffer;
		vk::DeviceMemory depthBufferMemory;
		vk::ImageView depthBufferView;
		vk::Format depthFormat;
		int width, height;


		vk::CommandBuffer commandBuffer;

		// synchronization
		vk::Semaphore imageAvailable, renderFinished;
		vk::Fence inFlight;

		// resources
		UBO cameraData;
		Buffer cameraDataBuffer;
		void* cameraDataWriteLocation;

		std::vector<glm::mat4> modelTransforms;
		Buffer modelBuffer;
		void* modelBufferWriteLocation;

		// resource descriptors
		vk::DescriptorBufferInfo uniformBufferDescriptor;
		vk::DescriptorBufferInfo modelBufferDescriptor;
		vk::DescriptorSet descriptorSet;

		void make_descriptor_resources();

		void make_depth_resources();

		void write_descriptor_set();

		void destroy();

	};

}