target_sources(${PLANAR_ENGINE_TARGET} PRIVATE
    EnumClassBase.hpp
    EnumClassBase.tpp
)

add_subdirectory(Concepts)
add_subdirectory(Log)
add_subdirectory(TypeTraits)
add_subdirectory(Time)
add_subdirectory(Terminal)
