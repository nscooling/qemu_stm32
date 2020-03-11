/* THIS FILE IS AUTOMATICALLY GENERATED, DO NOT MODIFY */

/*
 * schema-defined QAPI event functions
 *
 * Copyright (c) 2014 Wenchao Xia
 *
 * Authors:
 *  Wenchao Xia   <wenchaoqemu@gmail.com>
 *
 * This work is licensed under the terms of the GNU LGPL, version 2.1 or later.
 * See the COPYING.LIB file in the top-level directory.
 *
 */

#include "qemu-common.h"
#include "test-qapi-event.h"
#include "test-qapi-visit.h"
#include "qapi/qmp-output-visitor.h"
#include "qapi/qmp-event.h"


void qapi_event_send_event_a(Error **errp)
{
    QDict *qmp;
    Error *local_err = NULL;
    QMPEventFuncEmit emit;
    emit = qmp_event_get_func_emit();
    if (!emit) {
        return;
    }

    qmp = qmp_event_build_dict("EVENT_A");

    emit(TEST_QAPI_EVENT_EVENT_A, qmp, &local_err);

    error_propagate(errp, local_err);
    QDECREF(qmp);
}

void qapi_event_send_event_b(Error **errp)
{
    QDict *qmp;
    Error *local_err = NULL;
    QMPEventFuncEmit emit;
    emit = qmp_event_get_func_emit();
    if (!emit) {
        return;
    }

    qmp = qmp_event_build_dict("EVENT_B");

    emit(TEST_QAPI_EVENT_EVENT_B, qmp, &local_err);

    error_propagate(errp, local_err);
    QDECREF(qmp);
}

void qapi_event_send_event_c(bool has_a,
                             int64_t a,
                             bool has_b,
                             UserDefOne *b,
                             const char *c,
                             Error **errp)
{
    QDict *qmp;
    Error *local_err = NULL;
    QMPEventFuncEmit emit;
    QmpOutputVisitor *qov;
    Visitor *v;
    QObject *obj;

    emit = qmp_event_get_func_emit();
    if (!emit) {
        return;
    }

    qmp = qmp_event_build_dict("EVENT_C");

    qov = qmp_output_visitor_new();
    g_assert(qov);

    v = qmp_output_get_visitor(qov);
    g_assert(v);

    /* Fake visit, as if all members are under a structure */
    visit_start_struct(v, NULL, "", "EVENT_C", 0, &local_err);
    if (local_err) {
        goto clean;
    }

    if (has_a) {
        visit_type_int(v, &a, "a", &local_err);
        if (local_err) {
            goto clean;
        }
    }
    if (has_b) {
        visit_type_UserDefOne(v, &b, "b", &local_err);
        if (local_err) {
            goto clean;
        }
    }
    visit_type_str(v, (char **)&c, "c", &local_err);
    if (local_err) {
        goto clean;
    }

    visit_end_struct(v, &local_err);
    if (local_err) {
        goto clean;
    }

    obj = qmp_output_get_qobject(qov);
    g_assert(obj != NULL);

    qdict_put_obj(qmp, "data", obj);
    emit(TEST_QAPI_EVENT_EVENT_C, qmp, &local_err);

 clean:
    qmp_output_visitor_cleanup(qov);
    error_propagate(errp, local_err);
    QDECREF(qmp);
}

void qapi_event_send_event_d(EventStructOne *a,
                             const char *b,
                             bool has_c,
                             const char *c,
                             bool has_enum3,
                             EnumOne enum3,
                             Error **errp)
{
    QDict *qmp;
    Error *local_err = NULL;
    QMPEventFuncEmit emit;
    QmpOutputVisitor *qov;
    Visitor *v;
    QObject *obj;

    emit = qmp_event_get_func_emit();
    if (!emit) {
        return;
    }

    qmp = qmp_event_build_dict("EVENT_D");

    qov = qmp_output_visitor_new();
    g_assert(qov);

    v = qmp_output_get_visitor(qov);
    g_assert(v);

    /* Fake visit, as if all members are under a structure */
    visit_start_struct(v, NULL, "", "EVENT_D", 0, &local_err);
    if (local_err) {
        goto clean;
    }

    visit_type_EventStructOne(v, &a, "a", &local_err);
    if (local_err) {
        goto clean;
    }
    visit_type_str(v, (char **)&b, "b", &local_err);
    if (local_err) {
        goto clean;
    }
    if (has_c) {
        visit_type_str(v, (char **)&c, "c", &local_err);
        if (local_err) {
            goto clean;
        }
    }
    if (has_enum3) {
        visit_type_EnumOne(v, &enum3, "enum3", &local_err);
        if (local_err) {
            goto clean;
        }
    }

    visit_end_struct(v, &local_err);
    if (local_err) {
        goto clean;
    }

    obj = qmp_output_get_qobject(qov);
    g_assert(obj != NULL);

    qdict_put_obj(qmp, "data", obj);
    emit(TEST_QAPI_EVENT_EVENT_D, qmp, &local_err);

 clean:
    qmp_output_visitor_cleanup(qov);
    error_propagate(errp, local_err);
    QDECREF(qmp);
}

const char *TEST_QAPIEvent_lookup[] = {
    "EVENT_A",
    "EVENT_B",
    "EVENT_C",
    "EVENT_D",
    NULL,
};
