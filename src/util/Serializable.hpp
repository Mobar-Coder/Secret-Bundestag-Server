/**
 * @file Serializable.hpp
 * @author paul
 * @date 30.11.20
 * Description here TODO
 */
#ifndef SECRETBUNDESTAGSERVER_SERIALIZABLE_HPP
#define SECRETBUNDESTAGSERVER_SERIALIZABLE_HPP

#include <nlohmann/json.hpp>

#define TO_MEMBER(x) {#x, t.x}
#define FROM_MEMBER(x) j.at(#x).get_to(t.x);

#define GENERATE_TO(type, ...) \
    void to_json(nlohmann::json &j, const type &t) { \
        j = nlohmann::json{ __VA_ARGS__ }; }

#define GENERATE_FROM(type, ...) \
    void from_json(const nlohmann::json &j, type &t) { __VA_ARGS__ }

#define JSON_CLASS(type, body) \
    class type {\
    friend void to_json(nlohmann::json &j, const type &t); \
    friend void from_json(const nlohmann::json &j, type &t); \
    body                       \
    };
#endif //SECRETBUNDESTAGSERVER_SERIALIZABLE_HPP
