target_sources(${PLANAR_ENGINE_OBJECT_TARGET} PRIVATE
    Asset.hpp
    Asset.tpp
    AssetFunction.hpp
    LoadAssetMacros.hpp
)

add_subdirectory(Component)
