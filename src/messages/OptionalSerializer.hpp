//
// Created by timluchterhand on 12.12.20.
//

#ifndef SECRETBUNDESTAGSERVER_OPTIONALSERIALIZER_HPP
#define SECRETBUNDESTAGSERVER_OPTIONALSERIALIZER_HPP
#include <nlohmann/json.hpp>

namespace nlohmann {
    template<typename T>
    struct adl_serializer<std::optional<T>> {
        static void to_json(json &j, const std::optional<T> &opt) {
            if (opt.has_value()) {
                j = opt.value();
            } else {
                j = nullptr;
            }
        }

        static void from_json(const json &j, std::optional<T> &opt) {
            if (j.is_null()) {
                opt = std::nullopt;
            } else {
                opt = j.get<T>();
            }
        }
    };
}
#endif //SECRETBUNDESTAGSERVER_OPTIONALSERIALIZER_HPP
