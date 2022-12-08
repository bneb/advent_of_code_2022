cc_library (
    name = "part01",
    hdrs = ["part01.h"],
)

cc_library (
    name = "part02",
    hdrs = ["part02.h"],
)

cc_library (
    name = "parse_input",
    hdrs = ["parse_input.h"],
    deps = [":crane", ":move"],
)

cc_library (
    name = "crane",
    hdrs = ["crane.h"],
)

cc_library (
    name = "move",
    hdrs = ["move.h"],
)

cc_binary (
    name = "main",
    srcs = ["main.cc"],
    deps = [
        ":part01",
        ":part02",
        ":parse_input"
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
  name = "parse_input_test",
  size = "small",
  srcs = ["parse_input_test.cc"],
  deps = [
    "@com_google_googletest//:gtest_main",
    ":crane",
    ":move",
    ":parse_input",
    ],
)

cc_test(
  name = "crane_test",
  size = "small",
  srcs = ["crane_test.cc"],
  deps = [
    "@com_google_googletest//:gtest_main",
    ":crane",
    ":move",
    ],
)
