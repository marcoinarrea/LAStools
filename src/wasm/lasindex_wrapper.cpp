#include "wasmcommon.cpp"
#include "lasindex.cpp"

int lasindex(const InputParams &params)
{
    auto args = params.vectorize();
    int argc = args.size();
    char **argv = args.data();

    fprintfCommand(argv);

    return main(argc, argv);
}

EMSCRIPTEN_BINDINGS(my_module)
{
    emscripten::class_<InputParams>("InputParams")
        .constructor<std::vector<std::string>>()
        .property("args", &InputParams::getArgs, &InputParams::setArgs);

    emscripten::function("lasindex", &lasindex);
}
