#pragma once
#include<iostream>
#include<string>
namespace EIF201 {
	
	struct NodoLocutor{
		std::string nombre;
		int turnosAsignados;
		NodoLocutor* siguiente;

		NodoLocutor(const std::string& n) : nombre(n), turnosAsignados(0), siguiente(nullptr)
		{
			std::cout << "[NodoLocutor creaso: " << n << "]" << std::endl;
		}
		~NodoLocutor() {
			std::cout << "[NodoLocutor destruido: " << nombre << "]" << std::endl;
		}
	};

}
