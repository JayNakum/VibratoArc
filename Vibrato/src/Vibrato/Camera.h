#pragma once

#include <glm/glm.hpp>
#include <vector>

namespace Vibrato
{
	class Camera
	{
	public:
		Camera(float verticalFOV, float nearClip, float farClip);

		bool onUpdate(float ts);
		void onResize(uint32_t width, uint32_t height);

		inline const glm::mat4& getProjection() const { return m_projection; }
		inline const glm::mat4& getInverseProjection() const { return m_inverseProjection; }
		inline const glm::mat4& getView() const { return m_view; }
		inline const glm::mat4& getInverseView() const { return m_inverseView; }

		inline const glm::vec3& getPosition() const { return m_position; }
		inline const glm::vec3& getDirection() const { return m_forwardDirection; }

		inline const std::vector<glm::vec3>& getRayDirections() const { return m_rayDirections; }
		
		float getRotationSpeed();
	private:
		void recalculateProjection();
		void recalculateView();
		void recalculateRayDirections();

	private:
		std::vector<glm::vec3> m_rayDirections;

		glm::mat4 m_projection{ 1.0f };
		glm::mat4 m_view{ 1.0f };
		glm::mat4 m_inverseProjection{ 1.0f };
		glm::mat4 m_inverseView{ 1.0f };

		float m_verticalFOV = 45.0f;
		float m_nearClip = 0.1f;
		float m_farClip = 100.0f;

		glm::vec3 m_position{ 0.0f, 0.0f, 0.0f };
		glm::vec3 m_forwardDirection{ 0.0f, 0.0f, 0.0f };

		glm::vec2 m_lastMousePosition{ 0.0f, 0.0f };

		uint32_t m_viewportWidth = 0, m_viewportHeight = 0;
	};
}
