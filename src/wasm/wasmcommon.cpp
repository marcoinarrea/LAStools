#include <emscripten.h>
#include <emscripten/bind.h>

namespace emscripten {
namespace internal {

    template <typename T, typename Allocator>
    struct BindingType<std::vector<T, Allocator>> {
        using ValBinding = BindingType<val>;
        using WireType = ValBinding::WireType;

        static WireType toWireType(const std::vector<T, Allocator> &vec)
        {
            return ValBinding::toWireType(val::array(vec));
        }

        static std::vector<T, Allocator> fromWireType(WireType value)
        {
            return vecFromJSArray<T>(ValBinding::fromWireType(value));
        }
    };

    template <typename T>
    struct TypeID<T,
                  typename std::enable_if_t<std::is_same<
                      typename Canonicalized<T>::type,
                      std::vector<typename Canonicalized<T>::type::value_type,
                                  typename Canonicalized<T>::type::allocator_type>>::value>> {
        static constexpr TYPEID get()
        {
            return TypeID<val>::get();
        }
    };

}  // namespace internal
}  // namespace emscripten

class InputParams {
public:
    InputParams(std::vector<std::string> args_array) : args(std::move(args_array)) {}

    std::vector<char *> vectorize() const
    {
        auto vec = std::vector<char *>{};
        vec.reserve(args.size() - 1);
        for (const auto &arg : args) {
            vec.push_back(const_cast<char *>(arg.c_str()));
        }
        return vec;
    }

    std::vector<std::string> getArgs() const
    {
        return args;
    }

    void setArgs(const std::vector<std::string> &args_)
    {
        args = args_;
    }

private:
    std::vector<std::string> args;
};

void fprintfCommand(char **argv) {
    fprintf(stdout, "Command:");

    char **ptr;
    for (ptr = argv; *ptr != NULL; ptr++)
        fprintf(stdout, " %s", *ptr);

    fprintf(stdout, "\n");
}