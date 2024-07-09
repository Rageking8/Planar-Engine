target_sources(${PLANAR_ENGINE_OBJECT_TARGET} PRIVATE
    Asset.hpp
    Asset.tpp
    AssetDatabase.hpp
    AssetDatabase.tpp
    AssetFunction.hpp
    LoadAssetMacros.hpp
)

add_subdirectory(Component)
