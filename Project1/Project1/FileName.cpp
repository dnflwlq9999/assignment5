#include "MyActor.h"
#include "Math/UnrealMathUtility.h" 
#include "Engine/Engine.h"


AMyActor::AMyActor() {
    PrimaryActorTick.bCanEverTick = true; 
    start = FVector2D(0, 0); 
}


void AMyActor::BeginPlay() {
    Super::BeginPlay();
  
    UE_LOG(LogTemp, Warning, TEXT("시작 위치: (%d, %d)"), static_cast<int32>(start.X), static_cast<int32>(start.Y));

    move();
}

int32 AMyActor::step() {
    return FMath::RandRange(0, 1); 
}


void AMyActor::move() {
    FVector2D current = start; 

    for (int32 i = 0; i < 10; ++i) {
        int32 stepX = step();
        int32 stepY = step();

        if (stepX >= 2 || stepY >= 2) {
            UE_LOG(LogTemp, Warning, TEXT("잘못된 이동 시도: (%d, %d)"), stepX, stepY);
            continue;
        }

        current.X += stepX;
        current.Y += stepY;

        UE_LOG(LogTemp, Warning, TEXT("현재 위치: (%d, %d)"), static_cast<int32>(current.X), static_cast<int32>(current.Y));
    }
}
