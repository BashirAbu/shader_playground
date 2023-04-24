#pragma once
#include "../core.h"
#include <cmath>
#include <initializer_list>
namespace SPG
{
	const double PI = 3.142857143;
	template<typename T>
	struct Vector2
	{
		Vector2() = default;
		Vector2(T _X, T _Y) 
		{
			X = _X;
			Y = _Y;
		}
		Vector2(std::initializer_list<T> list)
		{
			size_t index = 0;
			for (T element : list)
			{
				elements[index] = element;
				index++;
			}
		}

		Vector2<T>& operator = (std::initializer_list<T> list)
		{
			size_t index = 0;
			for (T element : list)
			{
				elements[index] = element;
				index++;
			}
			return *this;
		}
		struct
		{
			union
			{
				T elements[2] = { 0 };
				struct
				{
					T X;
					T Y;
				};
			};
		};
		float Magnitude() const
		{
			float result = sqrtf((float)((X * X) + (Y * Y)));
			return result;
		}
		void Normalize() 
		{
			float magnitude = Magnitude();
			X = X / magnitude;
			Y = Y / magnitude;
		}
	};
	using Vector2f = Vector2<float>;
	using Vector2i = Vector2<int32_t>;

	template<typename T>
	Vector2<T> Normalize(Vector2<T> vector) 
	{
		float magnitude = vector.Magnitude();
		vector.X = vector.X / magnitude;
		vector.Y = vector.Y / magnitude;
		return vector;
	}

	template <typename T>
	struct Vector3
	{
		Vector3() 
		{
			X = 0;
			Y = 0;
			Z = 0;
		}
		Vector3(T _X, T _Y, T _Z)
		{
			X = _X;
			Y = _Y;
			Z = _Z;
		}
		Vector3(std::initializer_list<T> list) 
		{
			size_t index = 0;
			for (T element : list) 
			{
				elements[index] = element;
				index++;
			}
		}

		Vector3<T>& operator = (std::initializer_list<T> list) 
		{
			size_t index = 0;
			for (T element : list)
			{
				elements[index] = element;
				index++;
			}
			return *this;
		}

		Vector3<T>& operator * ( float scalar)
		{
			X = X * scalar;
			Y = Y * scalar;
			Z = Z * scalar;
			return *this;
		}


		Vector3(Vector2<T> vec2, T _Z) 
		{
			X = vec2.X;
			Y = vec2.Y;
			Z = _Z;
		}

		
		struct
		{
			union
			{
				T elements[3] = { 0 };
				struct 
				{
					T X;
					T Y;
					T Z;
				};
			};
		};

		float Magnitude() const
		{
			float result = sqrtf((float)((X * X) + (Y * Y) + (Z * Z)));
			return result;
		}
		void Normalize()
		{
			float magnitude = Magnitude();
			X = X / magnitude;
			Y = Y / magnitude;
			Z = Z / magnitude;
		}
	};
	using Vector3f = Vector3<float>;
	using Vector3i = Vector3<int32_t>;
	template<typename T>
	Vector3<T> Normalize(const Vector3<T>& vector)
	{
		Vector3<T> result;
		float magnitude = vector.Magnitude();
		if (magnitude != 0)
		{
			result.X = vector.X / magnitude;
			result.Y = vector.Y / magnitude;
			result.Z = vector.Z / magnitude;
		}
		return result;
	}

	template<typename T>
	Vector3<T> Cross(const Vector3<T>& vecA, const Vector3<T>& vecB) 
	{
		Vector3<T> result;
		result.X = vecA.Y * vecB.Z - vecA.Z * vecB.Y;
		result.Y = vecA.Z * vecB.X - vecA.X * vecB.Z;
		result.Z = vecA.X * vecB.Y - vecA.Y * vecB.X;
		return result;
	}

	template<typename T>
	T Dot(const Vector3<T>& vecA, const Vector3<T>& vecB)
	{
		T result;
		result = vecA.X * vecB.X + vecA.Y * vecB.Y + vecA.Z * vecB.Z;
		return result;
	}

	template<typename T>
	Vector3<T> operator + (const Vector3<T>& vecA, const Vector3<T>& vecB)
	{
		Vector3<T> result;
		result.X = vecA.X + vecB.X;
		result.Y = vecA.Y + vecB.Y;
		result.Z = vecA.Z + vecB.Z;
		return result;
	}

	template<typename T>
	Vector3<T> operator - (const Vector3<T>& vecA, const Vector3<T>& vecB)
	{
		Vector3<T> result;
		result.X = vecA.X - vecB.X;
		result.Y = vecA.Y - vecB.Y;
		result.Z = vecA.Z - vecB.Z;
		return result;
	}
	template <typename T>
	struct Vector4
	{
		Vector4() = default;

		Vector4(T _X, T _Y, T _Z, T _W)
		{
			X = _X;
			Y = _Y;
			Z = _Z;
			W = _W;
		}
		Vector4(std::initializer_list<T> list)
		{
			size_t index = 0;
			for (T element : list)
			{
				elements[index] = element;
				index++;
			}
		}

		Vector4<T>& operator = (std::initializer_list<T> list)
		{
			size_t index = 0;
			for (T element : list)
			{
				elements[index] = element;
				index++;
			}
			return *this;
		}
		explicit Vector4(Vector2<T> vec2, T _Z, T _W)
		{
			X = vec2.X;
			Y = vec2.Y;
			Z = _Z;
			W = _W;
		}
		explicit Vector4(Vector3<T> vec3, T _W)
		{
			X = vec3.X;
			Y = vec3.Y;
			Z = vec3.Z;
			W = _W;
		}
		Vector3<T> ToVector3() 
		{
			return Vector3<T>(X, Y, Z);
		}
		union 
		{
			T elements[4] = {0};
			struct
			{
				union
				{
					T X;
					T R;
				};
				union
				{
					T Y;
					T G;
				};
				union
				{
					T Z;
					T B;
				};
				union
				{
					T W;
					T A;
				};
			};
		};
		float Magnitude()
		{
			float result = sqrtf((float)((X * X) + (Y * Y) + (Z * Z) + (W * W)));
			return result;
		}
		void Normalize()
		{
			float magnitude = Magnitude();
			X = X / magnitude;
			Y = Y / magnitude;
			Z = Z / magnitude;
			W = W / magnitude;

		}

	};
	using Vector4f = Vector4<float>;
	using Vector4i = Vector4<int32_t>;
	template<typename T>
	Vector4<T> Normalize(Vector4<T> vector)
	{
		float magnitude = vector.Magnitude();
		vector.X = vector.X / magnitude;
		vector.Y = vector.Y / magnitude;
		vector.Z = vector.Z / magnitude;
		vector.W = vector.W / magnitude;
		return vector;
	}


	template<typename T, size_t row, size_t column>
	struct Mat 
	{
		Mat() 
		{
		
		}
		Mat(std::initializer_list<T> list) 
		{
			size_t index = 0;
			for (T element : list) 
			{
				Data[index] = element;
				index++;
			}
		}
		Mat(T value) 
		{
			for (size_t i = 0; i < row; i++) 
			{
				for (size_t j = 0; j < column; j++)
				{
					if (i == j)
						Data[i + (column * j)] = value;
				}
			}
		}
		Mat<T, row, column>& operator = (std::initializer_list<T> list) 
		{
			size_t index = 0;
			for (T element : list)
			{
				Data[index] = element;
				index++;
			}
			return *this;
		}


		T* operator[](size_t index) 
		{
			return Data[index];
		}

		Mat<T, row, column>& operator / (float value) 
		{
			for (size_t i = 0; i < (row * column); i++)
			{
				Data[i] = Data[i] / value;
			}
			return *this;
		}

		Mat<T, row, column>& operator * (float value)
		{
			for (size_t i = 0; i < (row * column); i++)
			{
				Data[i] = Data[i] * value;
			}
			return *this;
		}

		void swapRows(Mat<T, row, column>& mat, int32_t row1, int32_t row2)
		{
			float temp[column] = { 0 };
			for (int32_t i = 0; i < column; i++)
			{
				temp[i] = mat.Data2D[row1][i];
				mat.Data2D[row1][i] = mat.Data2D[row2][i];
				mat.Data2D[row2][i] = temp[i];
			}
		}


		float Det()
		{
			if(row != column)
			{
				SOG_LOG_ERROR("Matrix is not a square matrix.");
				return 0;
			}
			int32_t k = 0;
			int32_t sign = 1;
			T det = 1;
			Mat<T, row, column> mat = *this;
			for (int32_t i = 0; i < row; i++)
			{
				for (int32_t j = i + 1; j < row; j++)
				{
					if (mat.Data2D[i][i] == 0)
					{
						for (k = i + 1; k < column; k++)
						{
							if (mat.Data2D[k][i] != 0)
							{
								swapRows(mat, k, i);
								sign *= -1;
								break;
							}
						}
						if (k == column)
						{
							return 0;
						}
					}
					float factor = mat.Data2D[j][i] / mat.Data2D[i][i];
					for (k = i; k < column; k++)
					{
						mat.Data2D[j][k] -= factor * mat.Data2D[i][k];
					}
				}
				det *= mat.Data2D[i][i];
			}
			return det * sign;
		}


		Mat <T, row, column> Inverse() 
		{
			int32_t k = 0;
			Mat<T, row, column> mat = *this;
			T temp[row][column + column] = {0};
			for (int32_t i = 0; i < row; i ++) 
			{
				for (int32_t j = 0; j < column; j++)
				{
					temp[i][j] = mat.Data2D[i][j];
				}
			}
			for (int32_t i = 0; i < row; i++)
			{
				temp[i][i + column] = 1.0f;
			}

			for (int32_t i = 0; i < row; i++)
			{
				for (int32_t j = i + 1; j < column * 2; j++)
				{
					if (temp[i][i] == 0)
					{
						for (k = i + 1; k < column * 2; k++)
						{
							if (temp[k][i] != 0)
							{
								int row1 = k;
								int row2 = i;
								float _temp[column*2] = { 0 };
								for (int32_t w = 0; w < column*2; w++)
								{
									_temp[w] = temp[row1][w];
									temp[row1][w] = temp[row2][w];
									temp[row2][w] = _temp[w];
								}
								break;
							}
						}
						if (k == column)
						{
							SOG_LOG_ERROR("Matrix is singular.");
							Mat<T, row, column> ret(1.0f);
							return ret;
						}
					}
				}
			}
			for (int32_t i = 0; i < row; i++) {

				for (int32_t j = 0; j < row; j++) {

					if (j != i) 
					{
						float factor = 0.0f;
						if(temp[i][i] != 0)
							factor = temp[j][i] / temp[i][i];
						for (int32_t k = 0; k < column + column; k++) {

							temp[j][k] -= temp[i][k] * factor;
						}
					}
				}
			}

			for (int32_t i = 0; i < row; i++)
			{
				
				if (temp[i][i] != 0)
				{
					T f = temp[i][i];
					for (int32_t j = 0; j < column + column; j++)
					{
						temp[i][j] = temp[i][j] / f;
					}
				}
			}
			for (int32_t i = 0; i < row; i++) 
			{
				for (int32_t j = 0; j < column; j++)
				{
					mat.Data2D[i][j] = temp[i][j + column];
				}
			}
			return mat;
		}
		union
		{
			T Data[row * column] = { 0 };
			T Data2D[row][column];
		};
		size_t GetNumberOfColumns() const { return m_Column; }
		size_t GetNumberOfRows() const { return m_Row; }
	private:
		size_t m_Column = column;
		size_t m_Row = row;

	};
	template<typename T, size_t row, size_t column>
	Mat<T, row, column> operator * (const Mat<T, row, column>& left, const Mat<T, row, column>& right)
	{
		Mat<T, row, column> result;
		for (int32_t i = 0; i < row; i++)
		{
			for (int32_t j = 0; j < column; j++)
			{
				for (int32_t k = 0; k < column; k++)
				{
					result.Data2D[i][j] += left.Data2D[i][k] * right.Data2D[k][j];
				}
			}
		}
		return result;
	}

	template<typename T>
	Vector4<T> operator * (const Vector4<T>& vec4, const Mat<T, 4, 4>& mat)
	{
		Vector4<T> result;
		result.elements[0] = mat.Data2D[0][0] * vec4.elements[0] + mat.Data2D[1][0] * vec4.elements[1] + mat.Data2D[2][0] * vec4.elements[2] + mat.Data2D[3][0] * vec4.elements[3];
		result.elements[1] = mat.Data2D[0][1] * vec4.elements[0] + mat.Data2D[1][1] * vec4.elements[1] + mat.Data2D[2][1] * vec4.elements[2] + mat.Data2D[3][1] * vec4.elements[3];
		result.elements[2] = mat.Data2D[0][2] * vec4.elements[0] + mat.Data2D[1][2] * vec4.elements[1] + mat.Data2D[2][2] * vec4.elements[2] + mat.Data2D[3][2] * vec4.elements[3];
		result.elements[3] = mat.Data2D[0][3] * vec4.elements[3] + mat.Data2D[1][3] * vec4.elements[1] + mat.Data2D[2][3] * vec4.elements[2] + mat.Data2D[3][3] * vec4.elements[3];
		return result;
	}
	template<typename T>
	Vector3<T> operator * (const Vector3<T>& vec3, const Mat<T, 3, 3>& mat)
	{
		Vector3<T> result;
		for (int32_t i = 0; i < 3; i++)
		{
			for (int32_t k = 0; k < 3; k++)
			{
				result.elements[i] += mat.Data2D[i][k] * vec3.elements[k];
			}
		}
		return result;
	}

	template<typename T>
	Vector2<T> operator * (const Vector2<T>& vec2, const Mat<T, 2, 2>& mat)
	{
		Vector2<T> result;
		for (int32_t i = 0; i < 2; i++)
		{
			for (int32_t k = 0; k < 2; k++)
			{
				result.elements[i] += mat.Data2D[i][k] * vec3.elements[k];
			}
		}
		return result;
	}


	template<typename T>
	Mat<T, 4, 4> Translate(Mat<T, 4, 4> mat, Vector3<T> vec) 
	{
		Mat<T, 4, 4> result = mat;
		result.Data2D[3][0] = mat.Data2D[3][0] + vec.elements[0];
		result.Data2D[3][1] = mat.Data2D[3][1] + vec.elements[1];
		result.Data2D[3][2] = mat.Data2D[3][2] + vec.elements[2];
		return result;
	}

	template<typename T>
	Mat<T, 3, 3> Translate(Mat<T, 3, 3> mat, Vector2<T> vec)
	{
		Mat<T, 3, 3> result = mat;
		result.Data2D[2][0] = mat.Data2D[2][0] + vec.elements[0];
		result.Data2D[2][1] = mat.Data2D[2][1] + vec.elements[1];
		return result;
	}

	template<typename T>
	Mat<T, 4, 4> Scale(Mat<T, 4, 4> mat, Vector3<T> vec)
	{
		Mat<T, 4, 4> result = mat;
		result.Data2D[0][0] *= vec.X;
		result.Data2D[1][1] *= vec.Y;
		result.Data2D[2][2] *= vec.Z;
		return result;
	}
	
	template<typename T, size_t row, size_t column>
	Mat<T, row, column> Rotate(Mat<T, row, column> mat, double angle, Vector3<T> u)
	{
		T c = T(cos(angle));
		T s = T(sin(angle));
		Mat<T, row, column> rotationMat;
		if (mat.GetNumberOfColumns() != 4) 
		{
			SOG_LOG_ERROR("Matrix dimension is not 4x4.");
			return rotationMat;
		}
		if (u.X != 0) {
			rotationMat = { 1, 0, 0, 0,
				            0, c, s, 0,
				            0, -s, c, 0,
				            0, 0, 0, 1 };
		}
		else if (u.Y != 0) 
		{
			rotationMat = { c, 0, -s, 0,
			                0, 1, 0, 0, 
			                s, 0, c, 0,
			                0, 0, 0, 1};
		}
		else if (u.Z != 0)
		{
			rotationMat = { c, s, 0, 0, 
				            -s, c, 0, 0,
				            0, 0, 1, 0,
				            0, 0, 0, 1};
		}
		else 
		{
			SOG_LOG_ERROR("Choose acix of rotation");
		}
		return rotationMat * mat;
	}

	template<typename T, size_t row, size_t column>
	Mat<T, row, column> Rotate(Mat<T, row, column> mat, double angle)
	{
		Mat<T, row, column> rotationMat;
		if (mat.GetNumberOfColumns() != 3)
		{
			SOG_LOG_ERROR("Matrix dimension is not 4x4.");
			return rotationMat;
		}
		rotationMat = { T(cos(angle)), T(-sin(angle)), 0,
		                T(sin(angle)), T(cos(angle)) , 0,
		                0            , 0             , 1};
		return rotationMat * mat;
	}
	template<typename T>
	Mat<T, 4, 4> OrthographicProjection(T left, T right, T bottom, T top, T _near, T _far) 
	{
		Mat<T, 4, 4> result;
		result = { T(2.0 / (right - left))              , 0                                    , 0                                    , 0,
				   0                                    , T(2.0 / (top - bottom))              , 0                                    , 0,
				   0                                    , 0                                    , T(-2.0 / (_far - _near))             , 0,
				   T(-((right + left) / (right - left))), T(-((top + bottom) / (top - bottom))), T(-((_far + _near) / (_far - _near))), 1
		};
		return result;
	}

	template<typename T>
	Mat<T,4 ,4> LookAt(Vector3<T> cameraPos, Vector3<T> target, Vector3<T> up)
	{
		Mat<T, 4, 4> result(1);
		Vector3<T> sub = target - cameraPos;
		Vector3<T> zaxis = Normalize(sub);
		Vector3<T> xaxis = Normalize(Cross(zaxis, up));
		Vector3<T> yaxis = Cross(xaxis, zaxis);

		zaxis = zaxis * -1;

		result = { xaxis.X, xaxis.Y, xaxis.Z, 0,
		           yaxis.X, yaxis.Y, yaxis.Z, 0,
		           zaxis.X, zaxis.Y, zaxis.Z, 0,
				   -Dot(xaxis, cameraPos)      , -Dot(yaxis, cameraPos)      , -Dot(zaxis, cameraPos)      , 1};

		return result;
	}

	static double Rad2Deg(double angle) 
	{
		return angle * (180.0 / PI);
	}

	static double Deg2Rad(double angle)
	{
		return angle * (PI / 180.0);
	}

	using Mat3f = Mat<float, 3, 3>;
	using Mat4f = Mat<float, 4, 4>;
}
