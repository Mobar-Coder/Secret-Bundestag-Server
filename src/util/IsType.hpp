/**
 * @file IsType.hpp
 * @author paul
 * @date 01.12.20
 * Description here TODO
 */
#ifndef SECRETBUNDESTAGSERVER_ISTYPE_HPP
#define SECRETBUNDESTAGSERVER_ISTYPE_HPP

#include <memory>

namespace util {
    template<typename T, typename P>
    auto isType(P p) { return std::dynamic_pointer_cast<T>(p) != nullptr; }

}

#endif //SECRETBUNDESTAGSERVER_ISTYPE_HPP
