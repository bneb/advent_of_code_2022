cc_library (
    name = "part01",
    hdrs = ["part01.h"],
    deps = [":util"]
)

cc_library (
    name = "part02",
    hdrs = ["part02.h"],
)

cc_library (
    name = "util",
    hdrs = ["util.h"],
)

cc_binary (
    name = "main",
    srcs = ["main.cc"],
    deps = [
        ":part01",
        ":part02"
    ]
)

cc_test(
  name = "part01_test",
  size = "small",
  srcs = ["part01_test.cc"],
  deps = [
    "@com_google_googletest//:gtest_main",
    ":part01"
    ],
)

cc_test(
  name = "part02_test",
  size = "small",
  srcs = ["part02_test.cc"],
  deps = [
    "@com_google_googletest//:gtest_main",
    ":part02",
    ],
)

cc_test(
  name = "util_test",
  size = "small",
  srcs = ["util_test.cc"],
  deps = [
    "@com_google_googletest//:gtest_main",
    ":util",
    ],
)
