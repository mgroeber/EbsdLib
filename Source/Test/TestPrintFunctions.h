#pragma once

#include <cstdio>
#include <iostream>
#include <memory>
#include <sstream>

#include "EbsdLib/Core/EbsdDataArray.hpp"
#include "EbsdLib/Core/Quaternion.hpp"

static const std::string DCName("Orientation Transforms Test");
static const std::string AMName("Angles");

#define s_NumReps 8

std::string k_InputNames[s_NumReps] = {"eu", "om", "qu", "ax", "ro", "ho", "cu", "st"};
int k_CompDims[s_NumReps] = {3, 9, 4, 4, 4, 3, 3, 3};

namespace OrientationPrinters
{

// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
template <typename T>
void Print_EU(const T& om)
{
  printf("EU:% 3.16f % 3.16f % 3.16f\n", om[0], om[1], om[2]);
}

// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
template <typename T>
void Print_OM(const T& om)
{
  printf("OM: /    % 3.16f    % 3.16f    % 3.16f    \\\n", om[0], om[1], om[2]);
  printf("OM: |    % 3.16f    % 3.16f    % 3.16f    |\n", om[3], om[4], om[5]);
  printf("OM: \\    % 3.16f    % 3.16f    % 3.16f    /\n", om[6], om[7], om[8]);
}

// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
template <typename T>
void Print_AX(const T& om)
{
  printf("Ax:<% 3.16f % 3.16f % 3.16f>% 3.16f\n", om[0], om[1], om[2], om[3]);
}

// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
template <typename T>
void Print_RO(const T& om)
{
  // if(om[3] != std::numeric_limits<K>::infinity())
  //  printf("Rodrigues vector                 :   % 3.6f    % 3.6f    % 3.6f\n", om[0], om[1], om[2] );
  // else
  printf("Ro:% 3.16f % 3.16f % 3.16f % 3.16f\n", om[0], om[1], om[2], om[3]);
}

// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
template <typename T>
void Print_HO(const T& om)
{
  printf("Ho:% 3.16f % 3.16f % 3.16f\n", om[0], om[1], om[2]);
}

// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
template <typename T>
void Print_QU(const T& om, typename T::Order layout)
{
  if(layout == T::Order::VectorScalar)
  {
    printf("QU:<% 3.16f % 3.6f % 3.16f> % 3.16f\n", om[0], om[1], om[2], om[3]);
  }

  else if(layout == T::Order::ScalarVector)
  {
    printf("QU: % 3.16f <% 3.16f % 3.16f % 3.16f>\n", om[0], om[1], om[2], om[3]);
  }
}

// -----------------------------------------------------------------------------
template <typename QuaternionType>
void Print_QU(const QuaternionType& q)
{
  printf("QU:<% 3.16f % 3.6f % 3.16f> % 3.16f\n", q.x(), q.y(), q.z(), q.w());
}

// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
template <typename T>
void Print_CU(const T& om)
{
  printf("Cu:% 3.16f % 3.16f % 3.16f\n", om[0], om[1], om[2]);
}

// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
template <typename T>
void Print_ST(const T& om)
{
  printf("St:% 3.16f % 3.16f % 3.16f\n", om[0], om[1], om[2]);
}

// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
template <typename DataArrayClass>
void PrintTuple(typename DataArrayClass::Pointer data, size_t t)
{
  std::vector<size_t> cDims = data->getComponentDimensions();
  printf("%s\n", data->getName().c_str());
  for(int a = 0; a < cDims[0]; a++)
  {
    printf("% 3.16f", data->getComponent(t, a));
    if(a < cDims[0] - 1)
    {
      printf("  ");
    }
    if(cDims[0] == 9 && (a == 2 || a == 5))
    {
      printf("\n");
    }
  }
  printf("\n");
}
} // namespace OrientationPrinters
