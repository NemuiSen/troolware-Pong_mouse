#pragma once
template <typename T>
struct Vec2
{
	Vec2(): x(0), y(0) {}
	Vec2(T X, T Y): x(X), y(Y) {}
	Vec2(T a): x(a), y(a) {}

	T x;
	T y;
};

/*
 * GLFW tranaja con uns sistema de coordenanas cartesianas que en ambos ejes (x, y) su valor es 1
 * tanto en la dirección positiva o negativa
 * ==================
 *		   ^
 *         |
 * <--------------->
 *		   |
 *		   |
 * ==================
 * 
 * Acambio el mouse funciona con el sistema de coordenadas del sistema operativo
 * en el cual su centro se encentra en la esquina superios izquierda
 * y el valor de los ejes (x, y) valen el ancho y alto en pixeles respectivamente
 * 
 * esta funcion permite convertir las coordenadas del sistema a coordenadas GLFW 
 */
inline Vec2<float> pixToCoord(const Vec2<int> &size, const Vec2<float> &pos)
{
	return {
		  pos.x / size.x * 2 - 1,
		-(pos.y / size.y * 2 - 1)
	};
}
