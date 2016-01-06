#include <iostream>
#include <vector>
#include <regex>

#include <sqlite3ext.h>

extern "C" {

SQLITE_EXTENSION_INIT1

static void regexp(sqlite3_context *ctx, int argc, sqlite3_value **argv) {
  auto regexp = (const char *) sqlite3_value_text(argv[0]);
  auto value = (const char *) sqlite3_value_text(argv[1]);

  try {

  auto res = std::regex_search(value, std::regex(regexp));
  sqlite3_result_int(ctx, res);

  }
  catch(std::exception& e) {
    sqlite3_result_error(ctx, e.what(), -1);
  }
}

int sqlite3_extension_init(sqlite3 *db, char **err, const sqlite3_api_routines *api) {
  SQLITE_EXTENSION_INIT2(api);
  sqlite3_create_function(db, "REGEXP", 2, SQLITE_UTF8 | SQLITE_DETERMINISTIC, nullptr, regexp, nullptr, nullptr);
  return 0;
}

}
