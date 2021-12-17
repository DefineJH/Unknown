// Fill out your copyright notice in the Description page of Project Settings.


#include "Hashing_Obj.h"
#include "Hash/CityHash.h"
#include "Misc/Parse.h"
#include <iostream>     
#include <sstream>
#include <string>
FString UHashing_Obj::GetHash(FString Name, int seed)
{
	std::string str(TCHAR_TO_UTF8(*Name));
	uint64 hash = CityHash64WithSeed(str.c_str(), str.size(), seed);

	std::ostringstream ss;
	ss << hash;

	std::string hash_str;
	hash_str = ss.str();

	FString f(hash_str.c_str());

	return f;
}