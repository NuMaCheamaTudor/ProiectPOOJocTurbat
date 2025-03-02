
#include "Salvare.h"

Salvare::Salvare()
{
	UE_LOG(LogTemp, Warning, TEXT("A"));
}
Salvare::Salvare(const Salvare& Other)
{
    UE_LOG(LogTemp, Warning, TEXT("A"));
}

Salvare::~Salvare()
{
        UE_LOG(LogTemp, Warning, TEXT("B"));
    
}
Salvare& Salvare::operator=(const Salvare& Other)
{
    if (this != &Other) 
    {
       
    }
    return *this;
}
