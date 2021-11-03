# This files gather compiler flags that are common to g++, clang and
# pathCC

tfel_add_cxx_compiler_flag_if_available(COMPILER_WARNINGS "Wall" "W" "Wshadow")
tfel_add_cxx_compiler_flag_if_available(COMPILER_WARNINGS "Wpointer-arith" "Wcast-qual" "Wcast-align")
tfel_add_cxx_compiler_flag_if_available(COMPILER_WARNINGS "Wwrite-strings" "Wctor-dtor-privacy" "Wnon-virtual-dtor")
tfel_add_cxx_compiler_flag_if_available(COMPILER_WARNINGS "Woverloaded-virtual" "Wreturn-type" "Wfloat-equal")
tfel_add_cxx_compiler_flag_if_available(COMPILER_WARNINGS "Wno-endif-labels" "Wmissing-format-attribute")
tfel_add_cxx_compiler_flag_if_available(COMPILER_WARNINGS "Wno-multichar" "Wno-deprecated-declarations" "Wpacked")
tfel_add_cxx_compiler_flag_if_available(COMPILER_WARNINGS "Wredundant-decls")
tfel_add_cxx_compiler_flag_if_available(COMPILER_WARNINGS "Wunknown-pragmas" "Wundef" "Wreorder")
tfel_add_cxx_compiler_flag_if_available(COMPILER_WARNINGS "Wno-conversion")
tfel_add_cxx_compiler_flag_if_available(COMPILER_WARNINGS "Wdouble-promotion")
tfel_add_cxx_compiler_flag_if_available(COMPILER_WARNINGS "Winit-self")
tfel_add_cxx_compiler_flag_if_available(COMPILER_WARNINGS "Wlogical-op")
tfel_add_cxx_compiler_flag_if_available(COMPILER_WARNINGS "Wmissing-include-dirs")
tfel_add_cxx_compiler_flag_if_available(COMPILER_WARNINGS "Wnoexcept")
tfel_add_cxx_compiler_flag_if_available(COMPILER_WARNINGS "Wold-style-cast")
tfel_add_cxx_compiler_flag_if_available(COMPILER_WARNINGS "Wstrict-null-sentinel")
tfel_add_cxx_compiler_flag_if_available(COMPILER_WARNINGS "Wtrampolines")
tfel_add_cxx_compiler_flag_if_available(COMPILER_WARNINGS "Wvector-operation-performance")
tfel_add_cxx_compiler_flag_if_available(COMPILER_WARNINGS "Wignored-qualifiers")
tfel_add_cxx_compiler_flag_if_available(COMPILER_WARNINGS "Wsequence-point")
# tfel_add_cxx_compiler_flag_if_available(COMPILER_WARNINGS "Wsuggest-attribute=pure")
# tfel_add_cxx_compiler_flag_if_available(COMPILER_WARNINGS "Wsuggest-attribute=const")
# tfel_add_cxx_compiler_flag_if_available(COMPILER_WARNINGS "Wsuggest-attribute=noreturn")
# tfel_add_cxx_compiler_flag_if_available(COMPILER_WARNINGS "Wsuggest-attribute=format")
tfel_add_cxx_compiler_flag_if_available(COMPILER_WARNINGS "Wswitch-bool")
tfel_add_cxx_compiler_flag_if_available(COMPILER_WARNINGS "Wlogical-not-parentheses")
tfel_add_cxx_compiler_flag_if_available(COMPILER_WARNINGS "Wsizeof-array-argument")
tfel_add_cxx_compiler_flag_if_available(COMPILER_WARNINGS "Wbool-compare")
# tfel_add_cxx_compiler_flag_if_available(COMPILER_WARNINGS "Winline")
tfel_add_cxx_compiler_flag_if_available(COMPILER_WARNINGS "Wshift-negative-value")
tfel_add_cxx_compiler_flag_if_available(COMPILER_WARNINGS "Wshift-overflow")
tfel_add_cxx_compiler_flag_if_available(COMPILER_WARNINGS "Wtautological-compare")
tfel_add_cxx_compiler_flag_if_available(COMPILER_WARNINGS "Wnull-dereference")
tfel_add_cxx_compiler_flag_if_available(COMPILER_WARNINGS "Wduplicated-cond")
tfel_add_cxx_compiler_flag_if_available(COMPILER_WARNINGS "Wmisleading-indentation")
tfel_add_cxx_compiler_flag_if_available(COMPILER_WARNINGS "Wduplicated-branches")
tfel_add_cxx_compiler_flag_if_available(COMPILER_WARNINGS "Wregister")
tfel_add_cxx_compiler_flag_if_available(COMPILER_WARNINGS "Wint-in-bool-context")
tfel_add_cxx_compiler_flag_if_available(COMPILER_WARNINGS "Wsuggest-override")

if(enable-developer-warnings)
  tfel_add_cxx_compiler_flag_if_available(COMPILER_WARNINGS "Wextra")
  tfel_add_cxx_compiler_flag_if_available(COMPILER_WARNINGS "pedantic")
  tfel_add_cxx_compiler_flag_if_available(COMPILER_WARNINGS "Wsign-compare")
  tfel_add_cxx_compiler_flag_if_available(COMPILER_WARNINGS "Wswitch")
  tfel_add_cxx_compiler_flag_if_available(COMPILER_WARNINGS "Wmissing-declarations")
  tfel_add_cxx_compiler_flag_if_available(COMPILER_WARNINGS "Wzero-as-null-pointer-constant")
  tfel_add_cxx_compiler_flag_if_available(COMPILER_WARNINGS "Wsign-conversion")
  tfel_add_cxx_compiler_flag_if_available(COMPILER_WARNINGS "Wsign-promo")
  if(NOT (WIN32 AND ( CMAKE_SIZEOF_VOID_P EQUAL 8 )))
    tfel_add_cxx_compiler_flag_if_available(COMPILER_WARNINGS "Wlong-long")
  endif(NOT (WIN32 AND ( CMAKE_SIZEOF_VOID_P EQUAL 8 )))
else(enable-developer-warnings)
  tfel_add_cxx_compiler_flag_if_available(COMPILER_WARNINGS "Wno-switch-enum")
  tfel_add_cxx_compiler_flag_if_available(COMPILER_WARNINGS "Wno-covered-switch-default")
  tfel_add_cxx_compiler_flag_if_available(COMPILER_WARNINGS "Wno-covered-switch-default")
  tfel_add_cxx_compiler_flag_if_available(COMPILER_WARNINGS "Wno-sign-compare")
  tfel_add_cxx_compiler_flag_if_available(COMPILER_WARNINGS "Wno-missing-declarations")
  tfel_add_cxx_compiler_flag_if_available(COMPILER_WARNINGS "Wno-weak-vtables")
  tfel_add_cxx_compiler_flag_if_available(COMPILER_WARNINGS "Wno-unused-macros")
endif(enable-developer-warnings)


if(enable-advanced-developer-warnings)
  tfel_add_cxx_compiler_flag_if_available(COMPILER_WARNINGS "Wsuggest-final-types")
  tfel_add_cxx_compiler_flag_if_available(COMPILER_WARNINGS "Wsuggest-final-methods")
endif(enable-advanced-developer-warnings)
