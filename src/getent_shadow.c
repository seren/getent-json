#include <sys/types.h>
#include <shadow.h>
#include <json-c/json.h>

#include "getent_shadow.h"

json_object * getent_shadow() {
  struct spwd *s;
  struct json_object * j_arr = json_object_new_array();

  setspent();

  while ((s = getspent()) != NULL) {
    struct json_object * o = json_object_new_object();
    json_object_object_add(o, "name", json_object_new_string(s->sp_namp));
    json_object_object_add(o, "password", json_object_new_string(s->sp_pwdp));

    json_object_object_add(o, "last_change", json_object_new_int(s->sp_lstchg));
    json_object_object_add(
        o, "days_until_change_required", json_object_new_int(s->sp_min));
    json_object_object_add(
        o, "days_until_change_allowed", json_object_new_int(s->sp_max));
    json_object_object_add(
        o, "days_until_warning", json_object_new_int(s->sp_warn));
    json_object_object_add(
        o, "days_until_inactive", json_object_new_int(s->sp_inact));
    json_object_object_add(
        o, "days_until_inactive", json_object_new_int(s->sp_expire));
    json_object_object_add(
        o, "future_flag", json_object_new_int(s->sp_flag));

    json_object_array_add(j_arr, o);
  }

  endspent();

  if (s) {
    free(s);
  }

  return j_arr;
}
