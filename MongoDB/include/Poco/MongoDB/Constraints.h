#pragma once
#include <concepts>

namespace constraints{
template <class ContainerType> 
    concept Vectorable = requires(ContainerType& c) 
    {
        {c.begin() };
        { c.end() };
        { c.size() };
        { c.push_back(ContainerType::value_type) };
    };

   template <class ContainerType> 
    concept Mapable = requires(ContainerType& c) 
    {
        {c.begin() };
        { c.end() };
        { c.size() };
        { ContainerType::key_type};
        { ContainerType::mapped_type};
    };

   template <class Optional> 
    concept Optionable = requires(Optional& c) 
    {
        { c.value() };
        { c.value_or(Optional::value_type) };
        { c.size() };
        { Optional::key_type};
        { Optional::mapped_type};
    };

   template <class Pointer> 
    concept Pointerable = requires(Pointer& c) 
    {
        { c.get() };
        { *c };
        { Pointer::element_type };
        { c.use_count()};
    };
}