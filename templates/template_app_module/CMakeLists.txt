set(APP_NAME "MODULE_NAME_app")
set(ELF_FILE ${APP_NAME}.elf)
set(HEX_FILE ${APP_NAME}.hex)
set(SOURCE_DIR "src")
set(PRIVATE_HEADER_DIR "src")
set(PUBLIC_HEADER_DIR "include")
file(GLOB_RECURSE SOURCES "${SOURCE_DIR}/*.c")

add_executable(${ELF_FILE} ${SOURCES})

target_include_directories(
  ${ELF_FILE}
  PUBLIC ${PUBLIC_HEADER_DIR}
  PRIVATE ${PRIVATE_HEADER_DIR})

target_link_libraries(${ELF_FILE} PRIVATE project_warnings)

add_custom_command(
  TARGET ${ELF_FILE}
  POST_BUILD
  COMMAND avr-objcopy -j .text -j .data -O ihex ${ELF_FILE} ${HEX_FILE}
  COMMENT "Generating ${HEX_FILE}")
