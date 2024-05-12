#pragma once

#define PLANAR_DELETE_COPY_FUNCTIONS(type) \
    type(const type&) = delete;            \
    type& operator=(const type&) = delete; \
