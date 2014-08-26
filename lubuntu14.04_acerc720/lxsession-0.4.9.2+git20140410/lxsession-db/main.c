/* main.c generated by valac 0.22.1, the Vala compiler
 * generated from main.vala, do not modify */

/* 
 *      Copyright 2013 Julien Lavergne <gilir@ubuntu.com>
 *
 *      This program is free software; you can redistribute it and/or modify
 *      it under the terms of the GNU General Public License as published by
 *      the Free Software Foundation; either version 2 of the License, or
 *      (at your option) any later version.
 *
 *      This program is distributed in the hope that it will be useful,
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *      GNU General Public License for more details.
 *
 *      You should have received a copy of the GNU General Public License
 *      along with this program; if not, write to the Free Software
 *      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 *      MA 02110-1301, USA.
 */

#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>


#define LXSESSION_TYPE_DB_DEFAULT_APPS (lxsession_db_default_apps_get_type ())
#define LXSESSION_DB_DEFAULT_APPS(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), LXSESSION_TYPE_DB_DEFAULT_APPS, LxsessionDBDefaultApps))
#define LXSESSION_DB_DEFAULT_APPS_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), LXSESSION_TYPE_DB_DEFAULT_APPS, LxsessionDBDefaultAppsClass))
#define LXSESSION_IS_DB_DEFAULT_APPS(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), LXSESSION_TYPE_DB_DEFAULT_APPS))
#define LXSESSION_IS_DB_DEFAULT_APPS_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), LXSESSION_TYPE_DB_DEFAULT_APPS))
#define LXSESSION_DB_DEFAULT_APPS_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), LXSESSION_TYPE_DB_DEFAULT_APPS, LxsessionDBDefaultAppsClass))

typedef struct _LxsessionDBDefaultApps LxsessionDBDefaultApps;
typedef struct _LxsessionDBDefaultAppsClass LxsessionDBDefaultAppsClass;

#define LXSESSION_TYPE_MAIN (lxsession_main_get_type ())
#define LXSESSION_MAIN(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), LXSESSION_TYPE_MAIN, LxsessionMain))
#define LXSESSION_MAIN_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), LXSESSION_TYPE_MAIN, LxsessionMainClass))
#define LXSESSION_IS_MAIN(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), LXSESSION_TYPE_MAIN))
#define LXSESSION_IS_MAIN_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), LXSESSION_TYPE_MAIN))
#define LXSESSION_MAIN_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), LXSESSION_TYPE_MAIN, LxsessionMainClass))

typedef struct _LxsessionMain LxsessionMain;
typedef struct _LxsessionMainClass LxsessionMainClass;
typedef struct _LxsessionMainPrivate LxsessionMainPrivate;
#define _g_option_context_free0(var) ((var == NULL) ? NULL : (var = (g_option_context_free (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_main_loop_unref0(var) ((var == NULL) ? NULL : (var = (g_main_loop_unref (var), NULL)))

struct _LxsessionMain {
	GObject parent_instance;
	LxsessionMainPrivate * priv;
};

struct _LxsessionMainClass {
	GObjectClass parent_class;
};


extern LxsessionDBDefaultApps* lxsession_global_db;
LxsessionDBDefaultApps* lxsession_global_db = NULL;
static gpointer lxsession_main_parent_class = NULL;
static gchar* lxsession_main_mode;
static gchar* lxsession_main_mode = NULL;

GType lxsession_db_default_apps_get_type (void) G_GNUC_CONST;
GType lxsession_main_get_type (void) G_GNUC_CONST;
enum  {
	LXSESSION_MAIN_DUMMY_PROPERTY
};
gint lxsession_main_main (gchar** args, int args_length1);
LxsessionDBDefaultApps* lxsession_db_default_apps_new (const gchar* mode_argument);
LxsessionDBDefaultApps* lxsession_db_default_apps_construct (GType object_type, const gchar* mode_argument);
void lxsession_db_default_apps_update (LxsessionDBDefaultApps* self);
static void _g_main_loop_quit_lxsession_db_default_apps_exit_now (LxsessionDBDefaultApps* _sender, gpointer self);
LxsessionMain* lxsession_main_new (void);
LxsessionMain* lxsession_main_construct (GType object_type);
static void lxsession_main_finalize (GObject* obj);

static const GOptionEntry LXSESSION_MAIN_option_entries[2] = {{"mode", 'm', 0, G_OPTION_ARG_STRING, &lxsession_main_mode, "specify the mode to launch (display or write)", "NAME"}, {NULL}};

static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void _g_main_loop_quit_lxsession_db_default_apps_exit_now (LxsessionDBDefaultApps* _sender, gpointer self) {
	g_main_loop_quit (self);
}


gint lxsession_main_main (gchar** args, int args_length1) {
	gint result = 0;
	LxsessionDBDefaultApps* db = NULL;
	const gchar* _tmp6_ = NULL;
	LxsessionDBDefaultApps* _tmp7_ = NULL;
	LxsessionDBDefaultApps* _tmp8_ = NULL;
	LxsessionDBDefaultApps* _tmp9_ = NULL;
	LxsessionDBDefaultApps* _tmp10_ = NULL;
	GMainLoop* loop = NULL;
	GMainLoop* _tmp11_ = NULL;
	LxsessionDBDefaultApps* _tmp12_ = NULL;
	GMainLoop* _tmp13_ = NULL;
	GMainLoop* _tmp14_ = NULL;
	GError * _inner_error_ = NULL;
	{
		GOptionContext* options_args = NULL;
		GOptionContext* _tmp0_ = NULL;
		GOptionContext* _tmp1_ = NULL;
		GOptionContext* _tmp2_ = NULL;
		GOptionContext* _tmp3_ = NULL;
		_tmp0_ = g_option_context_new ("- Lxsession database utility");
		options_args = _tmp0_;
		_tmp1_ = options_args;
		g_option_context_set_help_enabled (_tmp1_, TRUE);
		_tmp2_ = options_args;
		g_option_context_add_main_entries (_tmp2_, LXSESSION_MAIN_option_entries, NULL);
		_tmp3_ = options_args;
		g_option_context_parse (_tmp3_, &args_length1, &args, &_inner_error_);
		if (_inner_error_ != NULL) {
			_g_option_context_free0 (options_args);
			if (_inner_error_->domain == G_OPTION_ERROR) {
				goto __catch0_g_option_error;
			}
			_g_option_context_free0 (options_args);
			g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return 0;
		}
		_g_option_context_free0 (options_args);
	}
	goto __finally0;
	__catch0_g_option_error:
	{
		GError* e = NULL;
		GError* _tmp4_ = NULL;
		const gchar* _tmp5_ = NULL;
		e = _inner_error_;
		_inner_error_ = NULL;
		_tmp4_ = e;
		_tmp5_ = _tmp4_->message;
		g_critical ("main.vala:48: Option parsing failed: %s\n", _tmp5_);
		result = -1;
		_g_error_free0 (e);
		return result;
	}
	__finally0:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return 0;
	}
	gtk_init (&args_length1, &args);
	_tmp6_ = lxsession_main_mode;
	_tmp7_ = lxsession_db_default_apps_new (_tmp6_);
	db = _tmp7_;
	_tmp8_ = db;
	_tmp9_ = _g_object_ref0 (_tmp8_);
	_g_object_unref0 (lxsession_global_db);
	lxsession_global_db = _tmp9_;
	_tmp10_ = lxsession_global_db;
	lxsession_db_default_apps_update (_tmp10_);
	_tmp11_ = g_main_loop_new (NULL, FALSE);
	loop = _tmp11_;
	_tmp12_ = lxsession_global_db;
	_tmp13_ = loop;
	g_signal_connect (_tmp12_, "exit-now", (GCallback) _g_main_loop_quit_lxsession_db_default_apps_exit_now, _tmp13_);
	_tmp14_ = loop;
	g_main_loop_run (_tmp14_);
	result = 0;
	_g_main_loop_unref0 (loop);
	_g_object_unref0 (db);
	return result;
}


int main (int argc, char ** argv) {
	g_type_init ();
	return lxsession_main_main (argv, argc);
}


LxsessionMain* lxsession_main_construct (GType object_type) {
	LxsessionMain * self = NULL;
	self = (LxsessionMain*) g_object_new (object_type, NULL);
	return self;
}


LxsessionMain* lxsession_main_new (void) {
	return lxsession_main_construct (LXSESSION_TYPE_MAIN);
}


static void lxsession_main_class_init (LxsessionMainClass * klass) {
	gchar* _tmp0_ = NULL;
	lxsession_main_parent_class = g_type_class_peek_parent (klass);
	G_OBJECT_CLASS (klass)->finalize = lxsession_main_finalize;
	_tmp0_ = g_strdup ("");
	lxsession_main_mode = _tmp0_;
}


static void lxsession_main_instance_init (LxsessionMain * self) {
}


static void lxsession_main_finalize (GObject* obj) {
	LxsessionMain * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, LXSESSION_TYPE_MAIN, LxsessionMain);
	G_OBJECT_CLASS (lxsession_main_parent_class)->finalize (obj);
}


GType lxsession_main_get_type (void) {
	static volatile gsize lxsession_main_type_id__volatile = 0;
	if (g_once_init_enter (&lxsession_main_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (LxsessionMainClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) lxsession_main_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (LxsessionMain), 0, (GInstanceInitFunc) lxsession_main_instance_init, NULL };
		GType lxsession_main_type_id;
		lxsession_main_type_id = g_type_register_static (G_TYPE_OBJECT, "LxsessionMain", &g_define_type_info, 0);
		g_once_init_leave (&lxsession_main_type_id__volatile, lxsession_main_type_id);
	}
	return lxsession_main_type_id__volatile;
}



