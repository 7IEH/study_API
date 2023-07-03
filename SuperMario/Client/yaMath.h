#pragma once

// 크기, 방향을 가지고 있는 단위
// 기저 벡터 방향의 기준이 되는 벡터
// 벡터는 점이다


namespace ya::math
{
	struct Vector2
	{
		float x;
		float y;

		Vector2()
			: x(0.f)
			, y(0.f)
		{

		}

		Vector2(float x, float y)
			: x(x)
			, y(y)
		{

		}
	};
}