target_sources(${PLANAR_ENGINE_TARGET} PRIVATE
    EnumClassBase.hpp
    EnumClassBase.tpp
    EnumClassFlags.hpp
    EnumClassFlags.tpp
)

add_subdirectory(Concepts)
add_subdirectory(TypeTraits)
add_subdirectory(Time)
add_subdirectory(Terminal)
