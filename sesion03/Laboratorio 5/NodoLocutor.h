#pragma once
#include<iostream>
#include<string>
namespace EIF201 {
	
	struct NodoLocutor{
		std::string nombre;
		NodoLocutor* siguiente;

		NodoLocutor(const std::string& n) : nombre(n), siguiente(nullptr)
		{
			std::cout << "[NodoLocutor creaso: " << n << "]" << std::endl;
		}
		~NodoLocutor() {
			std::cout << "[NodoLocutor destruido: " << nombre << "]" << std::endl;
		}
	};

}
