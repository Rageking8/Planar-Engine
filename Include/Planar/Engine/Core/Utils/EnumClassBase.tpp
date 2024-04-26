template<typename T>
inline constexpr EnumClassBase<T>::EnumClassBase(T init_value) :
    value{ init_value }
{

}

template<typename T>
inline constexpr EnumClassBase<T>::operator T() const
{
    return value;
}
