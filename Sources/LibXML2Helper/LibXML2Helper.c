/************************************************************************//**
 *     PROJECT: LibXML2Helper
 *    FILENAME: LibXML2Helper.c
 *         IDE: AppCode
 *      AUTHOR: Galen Rhodes
 *        DATE: 11/5/20
 *
 * Copyright © 2020 Project Galen. All rights reserved.
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 *//************************************************************************/

#include "include/LibXML2Helper.h"

void saxErrorMessageHandler(void *ctx, const char *msg, ...) {
    LibXmlSAXUserData *userData = ctx;
    char              *tmp      = calloc(1, 1024);
    va_list           args;
    va_start(args, msg);
    vsnprintf(tmp, 1023, msg, args);
    va_end(args);
    userData->handler.errorSaxSwiftFunc(ctx, tmp);
    free(tmp);
}

void saxWarningMessageHandler(void *ctx, const char *msg, ...) {
    LibXmlSAXUserData *userData = ctx;
    char              *tmp      = calloc(1, 1024);
    va_list           args;
    va_start(args, msg);
    vsnprintf(tmp, 1023, msg, args);
    va_end(args);
    userData->handler.warningSaxSwiftFunc(ctx, tmp);
    free(tmp);
}

void saxFatalErrorMessageHandler(void *ctx, const char *msg, ...) {
    LibXmlSAXUserData *userData = ctx;
    char              *tmp      = calloc(1, 1024);
    va_list           args;
    va_start(args, msg);
    vsnprintf(tmp, 1023, msg, args);
    va_end(args);
    userData->handler.fatalErrorSaxSwiftFunc(ctx, tmp);
    free(tmp);
}

void addErrorHandlers(LibXmlSAXHandler *handler) {
    handler->saxHandler.error      = &saxErrorMessageHandler;
    handler->saxHandler.warning    = &saxWarningMessageHandler;
    handler->saxHandler.fatalError = &saxFatalErrorMessageHandler;
}
